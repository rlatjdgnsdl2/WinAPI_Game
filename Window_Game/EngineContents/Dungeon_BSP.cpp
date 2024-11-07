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
	//	����� ũ�Ⱑ �ּ� ũ�⺸�� ������ ������ ����
	if (node->width < MIN_SIZE || node->height < MIN_SIZE) {
		return false;
	}
	//	���η� �ڸ���� �ʺ� ���̺��� �۰ų�, ���� ���� ���� ������
	bool SplitHorizon = (node->width < node->height) || (Random.RandomInt(0,2));

	int CurMax = (SplitHorizon ? node->height : node->width) - MIN_SIZE;

	// ���� ������ ũ������ Ȯ��
	if (CurMax <= MIN_SIZE)
		return false;

	// ���� ��ġ�� ���� (MIN_SIZE���� max ���̿��� ���� ����)
	int SplitPos = Random.RandomInt(MIN_SIZE, CurMax);

	// ���η� ����
	if (SplitHorizon) {
		node->left = new Node{ node->x, node->y, node->width, SplitPos };
		node->right = new Node{ node->x, node->y + SplitPos, node->width, node->height - SplitPos };
	}
	// ���η� ����
	else {
		node->left = new Node{ node->x, node->y, SplitPos, node->height };
		node->right = new Node{ node->x + SplitPos, node->y, node->width - SplitPos, node->height };
	}
	// ��������� ������ ��� ����
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
	// ���� ��尡 ����(leaf)���� Ȯ�� (���� ���� �� �̻� ���ҵ��� ����)
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
	// ���� �Ǵ� ������ �ڽ� ��尡 ���� ���, ������ ���� �����Ƿ� �Լ��� ����
	if (!node->left || !node->right) return;
	
	// ���ʰ� ������ �ڽ� ��忡�� ���� �����ɴϴ�.
   // �� ����� ���� ����� ���� ������ ������ �����մϴ�.
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



