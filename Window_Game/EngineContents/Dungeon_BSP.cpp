#include "PreCompile.h"
#include "Dungeon_BSP.h"

#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "PMDContentsCore.h"



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
	Node* root = new Node{ 5, 5, width-10, height-10 };
	InitDungeon();
	split(*root);
	CreateRooms(root);
	//ConnectRooms(root);
	SetNaturally();
}

Room ADungeon_BSP::getRoom(Node* node) const
{

	if (node->isLeaf() && node->room.isValid()) return node->room;

	Room room;
	if (node->left) {
		room = getRoom(node->left);
		if (room.isValid()) return room;  // ���� ã�� ��� ��ȯ
	}
	if (node->right) {
		room = getRoom(node->right);
		if (room.isValid()) return room;  // ���� ã�� ��� ��ȯ
	}

	// ���� ���� ��� �⺻�� ��ȯ
	return Room();  // �Ǵ� Room�� �⺻��, Ȥ�� ���� ó��

}

const int MIN_SIZE = 8;

void ADungeon_BSP::split(Node& node)
{
	UEngineRandom Random;

	// ����� ũ�Ⱑ �ּ� ũ�⺸�� ������ ������ ����
	if (node.width < MIN_SIZE || node.height < MIN_SIZE) {
		return ;
	}

	// ���η� �ڸ��� ���η� �ڸ��� ����
	bool SplitHorizon = (node.width < node.height) || (Random.RandomInt(0, 2) == 1);

	// ���� ������ �ִ� ��ġ ���� (�ּ� ũ�⸦ ����Ͽ� ����)
	int CurMax = (SplitHorizon ? node.height : node.width) - MIN_SIZE;

	// ���� ������ ũ������ Ȯ��
	if (CurMax < MIN_SIZE) {
		return;
	}

	// ���� ��ġ�� ���� (MIN_SIZE���� CurMax ���̿��� �����ϰ� ����)
	int SplitPos = Random.RandomInt(MIN_SIZE, CurMax);

	// ���η� ����
	if (SplitHorizon) {
		node.left = new Node{ node.x, node.y, node.width, SplitPos };
		node.right = new Node{ node.x, node.y + SplitPos, node.width, node.height - SplitPos };
	}
	// ���η� ����
	else {
		node.left = new Node{ node.x, node.y, SplitPos, node.height };
		node.right = new Node{ node.x + SplitPos, node.y, node.width - SplitPos, node.height };
	}
	Node* NewNodeLeft = node.left;
	Node* NewNodeRight = node.right;

	// ��������� ������ ��� ����
	if (nullptr!=NewNodeLeft) {
		split(*NewNodeLeft);
	}
	if (nullptr != NewNodeRight) {
		split(*NewNodeRight);
	}

	return;
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
	bool IsLeaf = node->isLeaf();

	// ���� ��尡 ����(leaf)���� Ȯ�� (���� ���� �� �̻� ���ҵ��� ����)
	if (IsLeaf) {

		int a = 0;

		// ���� �ʺ�� ���̸� ��� ũ���� 1/2���� �����Ͽ� ����
		int RoomWidth = Random.RandomInt(3, max(3, node->width / 2));
		int RoomHeight = Random.RandomInt(3, max(3, node->height / 2));

		// ���� ��ġ�� ��� ���ο��� �����ϰ� ����
		int RoomLocation_X = Random.RandomInt(node->x, node->x + node->width - RoomWidth);
		int RoomLocation_Y = Random.RandomInt(node->y, node->y + node->height - RoomHeight);

		// ������ �� ������ ��忡 ����
		node->room = { RoomLocation_X, RoomLocation_Y, RoomWidth, RoomHeight };

		// ���� Ÿ���� ����
		for (int y = RoomLocation_Y; y < RoomLocation_Y + RoomHeight; ++y) {
			for (int x = RoomLocation_X; x < RoomLocation_X + RoomWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Ground.png", 4);
				SetTileType(x, y, TileType::GROUND);
				RoomLocations.push_back(FVector2D(x * 72, y * 72));
			}
		}
	}
	else {

		int a = 0;
		if (node->left) CreateRooms(node->left);
		if (node->right) CreateRooms(node->right);
	}
}

void ADungeon_BSP::ConnectRooms(Node* node)
{
	// ���� �Ǵ� ������ �ڽ� ��尡 ���� ���, ������ ���� �����Ƿ� �Լ��� ����
	if (!node->left || !node->right)
	{
		return;
	}


	// ���ʰ� ������ �ڽ� ��忡�� ���� �����ɴϴ�.
   // �� ����� ���� ����� ���� ������ ������ �����մϴ�.
	Room room1 = getRoom(node->left);
	Room room2 = getRoom(node->right);

	int startX = room1.x + room1.width / 2;
	int startY = room1.y + room1.height / 2;
	int endX = room2.x + room2.width / 2;
	int endY = room2.y + room2.height / 2;

	while (startX != endX) {
		SetTile(startX, startY, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startX += (startX < endX) ? 1 : -1;
	}
	while (startY != endY) {
		SetTile(startX, startX, CurDungeonName + "_Ground.png", 4);
		SetTileType(startX, startY, TileType::GROUND);
		startY += (startY < endY) ? 1 : -1;
	}
	ConnectRooms(node->left);
	ConnectRooms(node->right);
}


void ADungeon_BSP::SetNaturally()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (nullptr != Tiles[y][x].SpriteRenderer)
			{
				//	����Ÿ���̸�
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

				if (y >= 1 && x >= 1 && y <= height - 2 && x <= width - 2)
				{
					//	Ÿ�ϼ���
					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (0 <= y + i && 0 <= x + j && width > x + j && height > y + i)
							{
								//	����Ÿ�ϰ� Ÿ���̸��� ���ؼ� Ű������
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




