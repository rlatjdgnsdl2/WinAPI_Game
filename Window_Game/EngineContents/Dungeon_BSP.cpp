#include "PreCompile.h"
#include "Dungeon_BSP.h"

#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "PMDContentsCore.h"



ADungeon_BSP::ADungeon_BSP()
{
	Tiles.resize(Height, std::vector<Tile>(Width));
	SetActorLocation({ 0,0 });

}

ADungeon_BSP::~ADungeon_BSP()
{
	if (root != nullptr) {
		delete root;
	}
}


void ADungeon_BSP::RoomClear()
{
	RoomLocations.clear();
	if (root != nullptr) {
		delete root;
	}
}

void ADungeon_BSP::Generate(std::string_view _CurDungeonName)
{
	CurDungeonName = _CurDungeonName.data();
	root = new Node{ 5, 5, Width - 11, Height - 11 };
	InitDungeon();
	Split(root);
	CreateNaturalFeatures();
	CreateRooms(root);
	ConnectRooms(root);
	SetNaturally();
	SetNextPotal();
}

Room ADungeon_BSP::getRoom(Node* node) const
{
	if (node->isLeaf() && node->room.isValid()) return node->room;
	Room room;
	if (node->left) {
		room = getRoom(node->left);
		if (room.isValid()) return room;  // 방을 찾은 경우 반환
	}
	if (node->right) {
		room = getRoom(node->right);
		if (room.isValid()) return room;  // 방을 찾은 경우 반환
	}
	// 방이 없을 경우 기본값 반환
	return Room();  // 또는 Room의 기본값, 혹은 예외 처리
}



void ADungeon_BSP::Split(Node* node)
{
	// 노드의 크기가 최소 크기보다 작으면 분할을 중지
	if (node->width < MIN_SIZE || node->height < MIN_SIZE) {
		return;
	}

	// 가로로 자를지 세로로 자를지 결정
	bool SplitHorizon = (node->width < node->height) || (Random.RandomInt(0, 1) == 1);

	// 분할 가능한 최대 위치 설정 (최소 크기를 고려하여 설정)
	int CurMax = (SplitHorizon ? node->height : node->width) - MIN_SIZE;

	// 분할 가능한 크기인지 확인
	if (CurMax <= MIN_SIZE) {
		return;
	}

	// 분할 위치를 설정 (MIN_SIZE부터 CurMax 사이에서 랜덤하게 선택)
	int SplitPos = Random.RandomInt(MIN_SIZE, CurMax);

	// 가로로 분할
	if (SplitHorizon) {
		node->left = new Node{ node->x, node->y, node->width, SplitPos };
		node->right = new Node{ node->x, node->y + SplitPos, node->width, node->height - SplitPos };
	}
	// 세로로 분할
	else {
		node->left = new Node{ node->x, node->y, SplitPos, node->height };
		node->right = new Node{ node->x + SplitPos, node->y, node->width - SplitPos, node->height };
	}
	Node* NewNodeLeft = node->left;
	Node* NewNodeRight = node->right;

	// 재귀적으로 분할을 계속 진행
	if (nullptr != NewNodeLeft) {
		Split(NewNodeLeft);
	}
	if (nullptr != NewNodeRight) {
		Split(NewNodeRight);
	}
	return;
}


void ADungeon_BSP::InitDungeon()
{
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (Tiles[y][x].SpriteRenderer == nullptr) {
				CreateTile(x, y, { 72,72 }, CurDungeonName + "_Wall.png", 4);
				Tiles[y][x].SpriteRenderer->SetSpriteScale();
				SetTileType(x, y, TileType::WALL);

			}
			SetTile(x, y, CurDungeonName + "_Wall.png", 4);
			Tiles[y][x].SpriteRenderer->SetSpriteScale();
			SetTileType(x, y, TileType::WALL);
		}
	}
}


void ADungeon_BSP::CreateNaturalFeatures()
{
	for (int i = 0; i < 15; ++i) {
		int maxAttempts = 10; // 유효한 위치를 찾기 위한 최대 시도 횟수
		int FeatureWidth = 0, FeatureHeight = 0, FeatureX = 0, FeatureY = 0;

		for (int attempt = 0; attempt < maxAttempts; ++attempt) {
			// 자연환경 크기 설정 (3x3 ~ 6x6 범위 내)
			FeatureWidth = Random.RandomInt(3, 8);
			FeatureHeight = Random.RandomInt(3, 8);

			// 자연환경의 위치를 맵 크기 내에서 랜덤하게 설정
			FeatureX = Random.RandomInt(0, max(3, Width - FeatureWidth));
			FeatureY = Random.RandomInt(0, max(3, Height - FeatureHeight));
		}
		// 자연환경 타일 배치
		for (int y = FeatureY; y < FeatureY + FeatureHeight; ++y) {
			for (int x = FeatureX; x < FeatureX + FeatureWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Water.png", 4); // 예: 물 타일
				Tiles[y][x].SpriteRenderer->SetSpriteScale();
				SetTileType(x, y, TileType::WATER); // 물 타일 타입 설정
			}
		}
	}
}



void ADungeon_BSP::CreateRooms(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	bool IsLeaf = node->isLeaf();

	// 현재 노드가 리프(leaf)인지 확인 (리프 노드는 더 이상 분할되지 않음)
	if (IsLeaf) {

		int a = 0;

		int RoomWidth = Random.RandomInt(4, max(4, node->width - 4));
		int RoomHeight = Random.RandomInt(4, max(4, node->height - 4));

		// 방의 위치를 노드 내부에서 랜덤하게 설정
		int RoomLocation_X = Random.RandomInt(node->x + 2, node->x + 2 + node->width - RoomWidth);
		int RoomLocation_Y = Random.RandomInt(node->y + 2, node->y + 2 + node->height - RoomHeight);

		// 생성된 방 정보를 노드에 저장
		node->room = { RoomLocation_X, RoomLocation_Y, RoomWidth, RoomHeight };

		// 방의 타일을 설정
		for (int y = RoomLocation_Y; y < RoomLocation_Y + RoomHeight; ++y) {
			for (int x = RoomLocation_X; x < RoomLocation_X + RoomWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Ground.png", 4);
				Tiles[y][x].SpriteRenderer->SetSpriteScale();
				SetTileType(x, y, TileType::GROUND);
				RoomLocations.push_back(FVector2D(x * 72, y * 72));
			}
		}
	}
	else {
		if (node->left) CreateRooms(node->left);
		if (node->right) CreateRooms(node->right);
	}

}

void ADungeon_BSP::ConnectRooms(Node* node)
{
	// 왼쪽 또는 오른쪽 자식 노드가 없는 경우, 연결할 방이 없으므로 함수를 종료
	if (!node->left || !node->right) {
		return;
	}

	// 왼쪽과 오른쪽 자식 노드에서 방을 가져옵니다.
	// 각 노드의 가장 가까운 방을 가져와 복도로 연결합니다.
	Room room1 = getRoom(node->left);
	Room room2 = getRoom(node->right);

	// 방의 중심점 계산
	int startX = room1.x + room1.width / 2;
	int startY = room1.y + room1.height / 2;
	int endX = room2.x + room2.width / 2;
	int endY = room2.y + room2.height / 2;

	// 랜덤 중간점 추가
	int midX = Random.RandomInt(min(startX, endX), max(startX, endX));
	int midY = Random.RandomInt(min(startY, endY), max(startY, endY));

	// 첫 번째 구간: 시작점에서 중간점까지
	while (startX != midX) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		Tiles[startY][startX].SpriteRenderer->SetSpriteScale();
		SetTileType(startX, startY, TileType::GROUND);
		startX += (startX < midX) ? 1 : -1;
	}
	while (startY != midY) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		Tiles[startY][startX].SpriteRenderer->SetSpriteScale();
		SetTileType(startX, startY, TileType::GROUND);
		startY += (startY < midY) ? 1 : -1;
	}

	// 두 번째 구간: 중간점에서 끝점까지
	while (startX != endX) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		Tiles[startY][startX].SpriteRenderer->SetSpriteScale();
		SetTileType(startX, startY, TileType::GROUND);
		startX += (startX < endX) ? 1 : -1;
	}
	while (startY != endY) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		Tiles[startY][startX].SpriteRenderer->SetSpriteScale();
		SetTileType(startX, startY, TileType::GROUND);
		startY += (startY < endY) ? 1 : -1;
	}
	// 자식 노드 연결
	ConnectRooms(node->left);
	ConnectRooms(node->right);
}



void ADungeon_BSP::SetNaturally()
{
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			Tile& tile = Tiles[y][x];
			if (nullptr != tile.SpriteRenderer) {
				// 타일 종류 설정
				std::string SpriteName = tile.SpriteRenderer->GetCurSpriteName();
				std::string TypeName = SpriteName.substr(SpriteName.find('_'));

				if (TypeName == "_GROUND.PNG") { tile.TileType = TileType::GROUND; }
				else if (TypeName == "_WALL.PNG") { tile.TileType = TileType::WALL; }
				else if (TypeName == "_WATER.PNG") { tile.TileType = TileType::WATER; }

				// 경계 검사 후 타일 패턴 설정
				if (y > 0 && x > 0 && y < Height - 1 && x < Width - 1) {
					std::string FindKey;
					for (int i = -1; i <= 1; ++i) {
						for (int j = -1; j <= 1; ++j) {
							FindKey += (SpriteName == Tiles[y + i][x + j].SpriteRenderer->GetCurSpriteName()) ? "1" : "0";
						}
					}
					tile.SpriteRenderer->SetSprite(SpriteName, PMDContentsCore::GetTileIndex(FindKey));
				}
			}
		}
	}
}

void ADungeon_BSP::SetNextPotal()
{
	int MaxSize = RoomLocations.size() - 1;
	int Index = Random.RandomInt(0, MaxSize);
	FVector2D RoomLocation = RoomLocations[Index];
	FIntPoint RoomIndex = FIntPoint(RoomLocation.iX() / 72, RoomLocation.iY() / 72);
	SetTile(RoomIndex.X, RoomIndex.Y, "NextPotal.png", 0);
	Tiles[RoomIndex.Y][RoomIndex.X].SpriteRenderer->SetSpriteScale();
	PotalLocation = RoomLocation;

}




