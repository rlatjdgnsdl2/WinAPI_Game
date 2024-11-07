#include "PreCompile.h"
#include "Dungeon_BSP.h"

#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>



ADungeon_BSP::ADungeon_BSP(int _width, int _height) : width(_width), height(_height)
{
	Tiles.resize(height, std::vector<Tile>(width));
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
	Node* root = new Node{ 5, 5, width, height };
	InitDungeon();
	split(root);
	CreateRooms(root);
	ConnectRooms(root);
}

bool ADungeon_BSP::split(Node* node)
{
	UEngineRandom Random;
	//	노드의 크기가 최소 크기보다 작으면 분할을 중지
	if (node->width < MIN_SIZE || node->height < MIN_SIZE) {
		return false;
	}
	//	가로로 자르기는 너비가 높이보다 작거나, 랜덤 값에 의해 결정됨
	bool SplitHorizon = (node->width < node->height) || (Random.RandomInt(0,2));

	int CurMax = (SplitHorizon ? node->height : node->width) - MIN_SIZE;

	// 분할 가능한 크기인지 확인
	if (CurMax <= MIN_SIZE)
		return false;

	// 분할 위치를 설정 (MIN_SIZE부터 max 사이에서 랜덤 선택)
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
	// 재귀적으로 분할을 계속 진행
	split(node->left);
	split(node->right);
	return true;
}

void ADungeon_BSP::InitDungeon()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
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

void ADungeon_BSP::CreateRooms(Node* node)
{
	UEngineRandom Random;
	// 현재 노드가 리프(leaf)인지 확인 (리프 노드는 더 이상 분할되지 않음)
	if (node->isLeaf()){
		int RoomWidth = Random.RandomInt(MIN_SIZE, node->width - MIN_SIZE);
		int RoomHeight = Random.RandomInt(MIN_SIZE, node->height - MIN_SIZE);
		int RoomLocation_X = Random.RandomInt(node->x, node->width - RoomWidth);
		int RoomLocation_Y = Random.RandomInt(node->y, node->width - RoomHeight);
		node->room = { RoomLocation_X,  RoomLocation_Y, RoomWidth, RoomHeight };
		for (int y =  RoomLocation_Y; y < RoomLocation_Y + RoomHeight; ++y) {
			for (int x = RoomLocation_X; x < RoomLocation_X + RoomWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Ground.png", 4);
				SetTileType(x, y, TileType::GROUND);
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
	if (!node->left || !node->right) return;
	
	// 왼쪽과 오른쪽 자식 노드에서 방을 가져옵니다.
   // 각 노드의 가장 가까운 방을 가져와 복도로 연결합니다.
	Room room1 = getRoom(node->left);
	Room room2 = getRoom(node->right);

	int startX = room1.x + room1.width / 2;
	int startY = room1.y + room1.height / 2;
	int endX = room2.x + room2.width / 2;
	int endY = room2.y + room2.height / 2;

	while (startX != endX) {
		SetTile(startY, startX, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startX += (startX < endX) ? 1 : -1;
	}
	while (startY != endY) {
		SetTile(startY, startX, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startY += (startY < endY) ? 1 : -1;
	}
	ConnectRooms(node->left);
	ConnectRooms(node->right);
}



