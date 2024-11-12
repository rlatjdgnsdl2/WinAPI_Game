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
		if (room.isValid()) return room;  // ���� ã�� ��� ��ȯ
	}
	if (node->right) {
		room = getRoom(node->right);
		if (room.isValid()) return room;  // ���� ã�� ��� ��ȯ
	}
	// ���� ���� ��� �⺻�� ��ȯ
	return Room();  // �Ǵ� Room�� �⺻��, Ȥ�� ���� ó��
}



void ADungeon_BSP::Split(Node* node)
{
	// ����� ũ�Ⱑ �ּ� ũ�⺸�� ������ ������ ����
	if (node->width < MIN_SIZE || node->height < MIN_SIZE) {
		return;
	}

	// ���η� �ڸ��� ���η� �ڸ��� ����
	bool SplitHorizon = (node->width < node->height) || (Random.RandomInt(0, 1) == 1);

	// ���� ������ �ִ� ��ġ ���� (�ּ� ũ�⸦ ����Ͽ� ����)
	int CurMax = (SplitHorizon ? node->height : node->width) - MIN_SIZE;

	// ���� ������ ũ������ Ȯ��
	if (CurMax <= MIN_SIZE) {
		return;
	}

	// ���� ��ġ�� ���� (MIN_SIZE���� CurMax ���̿��� �����ϰ� ����)
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
	Node* NewNodeLeft = node->left;
	Node* NewNodeRight = node->right;

	// ��������� ������ ��� ����
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
		int maxAttempts = 10; // ��ȿ�� ��ġ�� ã�� ���� �ִ� �õ� Ƚ��
		int FeatureWidth = 0, FeatureHeight = 0, FeatureX = 0, FeatureY = 0;

		for (int attempt = 0; attempt < maxAttempts; ++attempt) {
			// �ڿ�ȯ�� ũ�� ���� (3x3 ~ 6x6 ���� ��)
			FeatureWidth = Random.RandomInt(3, 8);
			FeatureHeight = Random.RandomInt(3, 8);

			// �ڿ�ȯ���� ��ġ�� �� ũ�� ������ �����ϰ� ����
			FeatureX = Random.RandomInt(0, max(3, Width - FeatureWidth));
			FeatureY = Random.RandomInt(0, max(3, Height - FeatureHeight));
		}
		// �ڿ�ȯ�� Ÿ�� ��ġ
		for (int y = FeatureY; y < FeatureY + FeatureHeight; ++y) {
			for (int x = FeatureX; x < FeatureX + FeatureWidth; ++x) {
				SetTile(x, y, CurDungeonName + "_Water.png", 4); // ��: �� Ÿ��
				Tiles[y][x].SpriteRenderer->SetSpriteScale();
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
		int RoomLocation_X = Random.RandomInt(node->x + 2, node->x + 2 + node->width - RoomWidth);
		int RoomLocation_Y = Random.RandomInt(node->y + 2, node->y + 2 + node->height - RoomHeight);

		// ������ �� ������ ��忡 ����
		node->room = { RoomLocation_X, RoomLocation_Y, RoomWidth, RoomHeight };

		// ���� Ÿ���� ����
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

	// �� ��° ����: �߰������� ��������
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
	// �ڽ� ��� ����
	ConnectRooms(node->left);
	ConnectRooms(node->right);
}



void ADungeon_BSP::SetNaturally()
{
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			Tile& tile = Tiles[y][x];
			if (nullptr != tile.SpriteRenderer) {
				// Ÿ�� ���� ����
				std::string SpriteName = tile.SpriteRenderer->GetCurSpriteName();
				std::string TypeName = SpriteName.substr(SpriteName.find('_'));

				if (TypeName == "_GROUND.PNG") { tile.TileType = TileType::GROUND; }
				else if (TypeName == "_WALL.PNG") { tile.TileType = TileType::WALL; }
				else if (TypeName == "_WATER.PNG") { tile.TileType = TileType::WATER; }

				// ��� �˻� �� Ÿ�� ���� ����
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




