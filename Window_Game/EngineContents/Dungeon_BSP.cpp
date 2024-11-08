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
		if (room.isValid()) return room;  // ���� ã�� ��� ��ȯ
	}
	if (node->right) {
		room = getRoom(node->right);
		if (room.isValid()) return room;  // ���� ã�� ��� ��ȯ
	}

	// ���� ���� ��� �⺻�� ��ȯ
	return Room();  // �Ǵ� Room�� �⺻��, Ȥ�� ���� ó��

}



void ADungeon_BSP::split(Node* node)
{


	// ����� ũ�Ⱑ �ּ� ũ�⺸�� ������ ������ ����
	if (node->width < MIN_SIZE || node->height < MIN_SIZE) {
		return;
	}

	// ���η� �ڸ��� ���η� �ڸ��� ����
	bool SplitHorizon = (node->width < node->height) || (Random.RandomInt(0, 2) == 1);

	// ���� ������ �ִ� ��ġ ���� (�ּ� ũ�⸦ ����Ͽ� ����)
	int CurMax = (SplitHorizon ? node->height : node->width) - MIN_SIZE;

	// ���� ������ ũ������ Ȯ��
	if (CurMax < MIN_SIZE) {
		return;
	}

	// ���� ��ġ�� ���� (MIN_SIZE���� CurMax ���̿��� �����ϰ� ����)
	int SplitPos = Random.RandomInt(MIN_SIZE, CurMax);

	// ���η� ����
	if (SplitHorizon) {
		node->left = new Node{ node->x, node->y, node->width, SplitPos };
		node->right = new Node{ node->x, node->y + SplitPos, node->width, node->height - SplitPos };
		int a = 0;
	}
	// ���η� ����
	else {
		node->left = new Node{ node->x, node->y, SplitPos, node->height };
		node->right = new Node{ node->x + SplitPos, node->y, node->width - SplitPos, node->height };

		int a = 0;
	}
	Node* NewNodeLeft = node->left;
	Node* NewNodeRight = node->right;

	// ��������� ������ ��� ����
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
		int maxAttempts = 10; // ��ȿ�� ��ġ�� ã�� ���� �ִ� �õ� Ƚ��
		int FeatureWidth = 0, FeatureHeight = 0, FeatureX = 0, FeatureY = 0;

		for (int attempt = 0; attempt < maxAttempts; ++attempt) {
			// �ڿ�ȯ�� ũ�� ���� (3x3 ~ 6x6 ���� ��)
			FeatureWidth = Random.RandomInt(3, 10);
			FeatureHeight = Random.RandomInt(3, 10);

			// �ڿ�ȯ���� ��ġ�� �� ũ�� ������ �����ϰ� ����
			FeatureX = Random.RandomInt(0, Width - FeatureWidth);
			FeatureY = Random.RandomInt(0, Height - FeatureHeight);
		}

		// �ڿ�ȯ�� Ÿ�� ��ġ
		for (int y = FeatureY; y < FeatureY + FeatureHeight; ++y) {
			for (int x = FeatureX; x < FeatureX + FeatureWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Water.png", 5); // ��: �� Ÿ��
				SetTileType(x, y, TileType::WATER); // �� Ÿ�� Ÿ�� ����
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

	// ���� ��尡 ����(leaf)���� Ȯ�� (���� ���� �� �̻� ���ҵ��� ����)
	if (IsLeaf) {

		int a = 0;

		int RoomWidth = Random.RandomInt(4, max(4, node->width - 4));
		int RoomHeight = Random.RandomInt(4, max(4, node->height - 4));

		// ���� ��ġ�� ��� ���ο��� �����ϰ� ����
		int RoomLocation_X = Random.RandomInt(node->x + 2, node->x + 2 + node->width - RoomWidth - 2);
		int RoomLocation_Y = Random.RandomInt(node->y + 2, node->y + 2 + node->height - RoomHeight - 2);

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
		if (node->left) CreateRooms(node->left);
		if (node->right) CreateRooms(node->right);
	}

}

void ADungeon_BSP::ConnectRooms(Node* node)
{
	// ���� �Ǵ� ������ �ڽ� ��尡 ���� ���, ������ ���� �����Ƿ� �Լ��� ����
	if (!node->left || !node->right) {
		return;
	}

	// ���ʰ� ������ �ڽ� ��忡�� ���� �����ɴϴ�.
	// �� ����� ���� ����� ���� ������ ������ �����մϴ�.
	Room room1 = getRoom(node->left);
	Room room2 = getRoom(node->right);

	// ���� �߽��� ���
	int startX = room1.x + room1.width / 2;
	int startY = room1.y + room1.height / 2;
	int endX = room2.x + room2.width / 2;
	int endY = room2.y + room2.height / 2;

	// ���� �߰��� �߰�
	int midX = Random.RandomInt(min(startX, endX), max(startX, endX));
	int midY = Random.RandomInt(min(startY, endY), max(startY, endY));

	// ù ��° ����: ���������� �߰�������
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

	// �� ��° ����: �߰������� ��������
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

	// �ڽ� ��� ����
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

				if (y >= 1 && x >= 1 && y <= Height - 2 && x <= Width - 2)
				{
					//	Ÿ�ϼ���
					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (0 <= y + i && 0 <= x + j && Width > x + j && Height > y + i)
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




