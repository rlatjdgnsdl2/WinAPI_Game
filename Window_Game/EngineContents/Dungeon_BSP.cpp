#include "PreCompile.h"
#include "Dungeon_BSP.h"

#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "PMDContentsCore.h"



ADungeon_BSP::ADungeon_BSP(int _width, int _height) : Width(_width), Height(_height)
{
	Tiles.resize(Height, std::vector<Tile>(Width));
	SetActorLocation({ 0,0 });
}
ADungeon_BSP::~ADungeon_BSP()
{
	delete root;
}


void ADungeon_BSP::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void ADungeon_BSP::Generate()
{
	Node* root = new Node{ 5, 5, Width - 10, Height - 10 };
	InitDungeon();
	split(root);
	CreateNaturalFeatures();
	CreateRooms(root);
	ConnectRooms(root);
	SetNaturally();
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



void ADungeon_BSP::split(Node* node)
{


	// 노드의 크기가 최소 크기보다 작으면 분할을 중지
	if (node->width < MIN_SIZE || node->height < MIN_SIZE) {
		return;
	}

	// 가로로 자를지 세로로 자를지 결정
	bool SplitHorizon = (node->width < node->height) || (Random.RandomInt(0, 2) == 1);

	// 분할 가능한 최대 위치 설정 (최소 크기를 고려하여 설정)
	int CurMax = (SplitHorizon ? node->height : node->width) - MIN_SIZE;

	// 분할 가능한 크기인지 확인
	if (CurMax < MIN_SIZE) {
		return;
	}

	// 분할 위치를 설정 (MIN_SIZE부터 CurMax 사이에서 랜덤하게 선택)
	int SplitPos = Random.RandomInt(MIN_SIZE, CurMax);

	// 가로로 분할
	if (SplitHorizon) {
		node->left = new Node{ node->x, node->y, node->width, SplitPos };
		node->right = new Node{ node->x, node->y + SplitPos, node->width, node->height - SplitPos };
		int a = 0;
	}
	// 세로로 분할
	else {
		node->left = new Node{ node->x, node->y, SplitPos, node->height };
		node->right = new Node{ node->x + SplitPos, node->y, node->width - SplitPos, node->height };

		int a = 0;
	}
	Node* NewNodeLeft = node->left;
	Node* NewNodeRight = node->right;

	// 재귀적으로 분할을 계속 진행
	if (nullptr != NewNodeLeft) {
		split(NewNodeLeft);
	}
	if (nullptr != NewNodeRight) {
		split(NewNodeRight);
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
				SetTileType(x, y, TileType::WALL);
			}
			SetTile(x, y, CurDungeonName + "_Wall.png", 4);
			SetTileType(x, y, TileType::WALL);
		}
	}
}


void ADungeon_BSP::CreateNaturalFeatures()
{
	for (int i = 0; i < 10; ++i) {
		int maxAttempts = 10; // 유효한 위치를 찾기 위한 최대 시도 횟수
		int FeatureWidth = 0, FeatureHeight = 0, FeatureX = 0, FeatureY = 0;

		for (int attempt = 0; attempt < maxAttempts; ++attempt) {
			// 자연환경 크기 설정 (3x3 ~ 6x6 범위 내)
			FeatureWidth = Random.RandomInt(3, 10);
			FeatureHeight = Random.RandomInt(3, 10);

			// 자연환경의 위치를 맵 크기 내에서 랜덤하게 설정
			FeatureX = Random.RandomInt(0, Width - FeatureWidth);
			FeatureY = Random.RandomInt(0, Height - FeatureHeight);
		}

		// 자연환경 타일 배치
		for (int y = FeatureY; y < FeatureY + FeatureHeight; ++y) {
			for (int x = FeatureX; x < FeatureX + FeatureWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Water.png", 5); // 예: 물 타일
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
		int RoomLocation_X = Random.RandomInt(node->x + 2, node->x + 2 + node->width - RoomWidth - 2);
		int RoomLocation_Y = Random.RandomInt(node->y + 2, node->y + 2 + node->height - RoomHeight - 2);

		// 생성된 방 정보를 노드에 저장
		node->room = { RoomLocation_X, RoomLocation_Y, RoomWidth, RoomHeight };

		// 방의 타일을 설정
		for (int y = RoomLocation_Y; y < RoomLocation_Y + RoomHeight; ++y) {
			for (int x = RoomLocation_X; x < RoomLocation_X + RoomWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Ground.png", 4);
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
		SetTileType(startX, startY, TileType::GROUND);
		startX += (startX < midX) ? 1 : -1;
	}
	while (startY != midY) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startY += (startY < midY) ? 1 : -1;
	}

	// 두 번째 구간: 중간점에서 끝점까지
	while (startX != endX) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startX += (startX < endX) ? 1 : -1;
	}
	while (startY != endY) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startY += (startY < endY) ? 1 : -1;
	}

	// 자식 노드 연결
	ConnectRooms(node->left);
	ConnectRooms(node->right);
}



void ADungeon_BSP::SetNaturally()
{
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (nullptr != Tiles[y][x].SpriteRenderer)
			{
				//	현재타일이름
				std::string SpriteName = Tiles[y][x].SpriteRenderer->GetCurSpriteName();
				int FindIndex = SpriteName.find('_');
				std::string TypeName = SpriteName.substr(FindIndex);
				if ("_GROUND.PNG" == TypeName)
				{
					Tiles[y][x].TileType = TileType::GROUND;
				}
				else if ("_WALL.PNG" == TypeName)
				{
					Tiles[y][x].TileType = TileType::WALL;
				}
				else if ("_WATER.PNG" == TypeName)
				{
					Tiles[y][x].TileType = TileType::WATER;
				}

				if (y >= 1 && x >= 1 && y <= Height - 2 && x <= Width - 2)
				{
					//	타일세팅
					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (0 <= y + i && 0 <= x + j && Width > x + j && Height > y + i)
							{
								//	주위타일과 타일이름을 비교해서 키값생성
								std::string CompareName = Tiles[y + i][x + j].SpriteRenderer->GetCurSpriteName();
								if (SpriteName == CompareName) {
									FindKey += "1";
								}
								else if (SpriteName != CompareName) {
									FindKey += "0";
								}
							}
						}
					}
					int SpriteIndex = PMDContentsCore::GetTileIndex(FindKey);
					Tiles[y][x].SpriteRenderer->SetSprite(SpriteName, SpriteIndex);
				}
			}
		}
	}
}




