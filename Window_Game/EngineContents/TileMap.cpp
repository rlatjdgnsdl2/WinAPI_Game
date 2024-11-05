#include "PreCompile.h"
#include "TileMap.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

#include <EngineBase/EngineRandom.h>
#include "PMDContentsCore.h"
#include "DungeonGameMode.h"

std::vector<std::vector<TILETYPE>> ATileMap::AllTileTypes;
std::vector<FTransform>ATileMap::Rooms;

ATileMap::ATileMap()
{
	Tiles.resize(DungeonSize.Y, std::vector<Tile>(DungeonSize.X));
	AllTileTypes.resize(DungeonSize.Y, std::vector<TILETYPE>(DungeonSize.X));
	InitTileMap();
	SetActorLocation({ 0,0 });
}
ATileMap::~ATileMap()
{

}
void ATileMap::BeginPlay()
{
	Super::BeginPlay();

}

void ATileMap::CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName)
{
	if (nullptr == Tiles[_y][_x].SpriteRenderer)
	{
		USpriteRenderer* NewSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		Tiles[_y][_x].SpriteRenderer = NewSpriteRenderer;
	}
	Tiles[_y][_x].SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	Tiles[_y][_x].SpriteRenderer->SetSprite(_SpriteName, 4);
	Tiles[_y][_x].SpriteRenderer->SetComponentLocation({ (_x)*_Scale.X,(_y)*_Scale.Y });
	Tiles[_y][_x].SpriteRenderer->SetSpriteScale(1.0f);
	FVector2D TileLocation = Tiles[_y][_x].SpriteRenderer->GetComponentLocation();
	Tiles[_y][_x].TileTrans = FTransform(_Scale, TileLocation - _Scale);
}



void ATileMap::InitTileMap()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			CreateTile(x, y, FVector2D(72, 72), ADungeonGameMode::GetCurDungeonName() + "_Wall.png");
		}
	}
}

void ATileMap::SetTile(int _col, int _row, std::string_view _TileType)
{
	if (0 <= _col && 0 <= _row && 60 > _col && 40 > _row) {

		Tiles[_row][_col].SpriteRenderer->SetSprite(ADungeonGameMode::GetCurDungeonName() + _TileType.data(), 4);
	}
}


void ATileMap::SetAllWall()
{
	for (int _y = 0; _y < DungeonSize.Y; _y++)
	{
		for (int _x = 0; _x < DungeonSize.X; _x++)
		{
			SetTile(_x, _y, "_Wall.png");
		}
	}
}


void ATileMap::Tick(float _DeltaTime)
{
	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("TileMapPos : " + GetActorLocation().ToString());
	UEngineDebug::CoreOutPutString("x : " + std::to_string(testNumX));
	UEngineDebug::CoreOutPutString("Y : " + std::to_string(testNumY));

	if (UEngineInput::GetInst().IsDown('S'))
	{
		testNumY++;
	}
	if (UEngineInput::GetInst().IsDown('W'))
	{
		testNumY--;
	}
	if (UEngineInput::GetInst().IsDown('A'))
	{
		testNumX--;
	}
	if (UEngineInput::GetInst().IsDown('D'))
	{
		testNumX++;
	}
	if (UEngineInput::GetInst().IsDown('Q'))
	{
		SetTile(testNumX, testNumY, "_Ground.png");
	}
	if (UEngineInput::GetInst().IsDown('E'))
	{
		SetTile(testNumX, testNumY, "_Wall.png");
	}

	if (UEngineInput::GetInst().IsDown('Y')) {
		SetNaturally();
	}

}




void ATileMap::SetHallWay()
{
	UEngineRandom random;
	FIntPoint PreAnchor = FIntPoint(random.RandomInt(5, 54), random.RandomInt(5, 34));;
	AllGround.push_back(PreAnchor);

	for (int j = 0; j < 10; j++)
	{
		FIntPoint Anchor = FIntPoint(random.RandomInt(5, 54), random.RandomInt(5, 34));
		AllGround.push_back(Anchor);
		FIntPoint Distance = PreAnchor - Anchor;

		if (Distance.Y > 0) {
			for (int i = 0; i < Distance.Y; i++)
			{
				SetTile(Anchor.X, Anchor.Y + i, "_Ground.png");
				
				AllGround.push_back(FIntPoint(Anchor.X, Anchor.Y + i));
			}
		}
		//	pre가 위에 있다면
		else if (Distance.Y < 0) {
			for (int i = 0; i > Distance.Y; i--)
			{
				SetTile(Anchor.X, Anchor.Y + i, "_Ground.png");
				AllGround.push_back(FIntPoint(Anchor.X, Anchor.Y + i));
			}
		}
		//	pre가 오른쪽에 있다면
		if (Distance.X > 0) {
			for (int i = 0; i < Distance.X; i++)
			{
				SetTile(Anchor.X + i, Anchor.Y + Distance.Y, "_Ground.png");
				AllGround.push_back(FIntPoint(Anchor.X + i, Anchor.Y ));
			}
		}
		//	pre가 왼쪽에 있다면
		else if (Distance.X < 0) {
			for (int i = 0; i > Distance.X; i--)
			{
				SetTile(Anchor.X + i, Anchor.Y + Distance.Y, "_Ground.png");
				AllGround.push_back(FIntPoint(Anchor.X + i, Anchor.Y ));
			}
		}
		PreAnchor = Anchor;
	}

}

bool ATileMap::IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms) {
	for (const auto& room : rooms) {
		FIntPoint roomPos(room.Location.X, room.Location.Y);
		FIntPoint roomSize(room.Scale.X, room.Scale.Y);

		if (!(pos.X + size.X <= roomPos.X || pos.X >= roomPos.X + roomSize.X ||
			pos.Y + size.Y <= roomPos.Y || pos.Y >= roomPos.Y + roomSize.Y)) {
			return true; // 겹침
		}
	}
	return false; // 겹치지 않음
}

void ATileMap::SetRoom()
{
	
	UEngineRandom random;
	for (int i = 0; i < 7; i++) {
		FIntPoint RoomSize = FIntPoint(random.RandomInt(3, 10), random.RandomInt(3, 10));
		int maxValue = AllGround.size() - 1;
		int randomIndex = random.RandomInt(0, maxValue);
		FIntPoint SelectPos = AllGround[randomIndex];

		// 방이 맵 경계 내에 있고 겹치지 않는지 확인
		if (SelectPos.X + RoomSize.X < 59 && SelectPos.Y + RoomSize.Y < 39 &&
			!IsRoomOverlap(FIntPoint(SelectPos), RoomSize, Rooms)) {

			// 방 타일 배치
			for (int _y = 0; _y < RoomSize.Y; _y++) {
				for (int _x = 0; _x < RoomSize.X; _x++) {
					SetTile(_x + SelectPos.X, _y + SelectPos.Y, "_Ground.png");
				}
			}

			// 방 위치와 크기를 Rooms에 추가
			FTransform roomTransform;
			roomTransform.Location = FVector2D(SelectPos.X, SelectPos.Y);
			roomTransform.Scale = FVector2D(RoomSize.X, RoomSize.Y); // Scale을 방 크기로 저장
			Rooms.push_back(roomTransform);
		}
	}
}

void ATileMap::SetBorderWall()
{

	for (int _y = 0; _y < DungeonSize.Y; _y++)
	{
		for (int _x = 0; _x < DungeonSize.X; _x++)
		{
			if (_y <= 3 || _x <= 3 || _y >= 36 || _x >= 56)
			{
				//	가장자리는 벽으로
				SetTile(_x, _y, "_Wall.png");
			}
		}
	}
}

void ATileMap::SetNaturally()
{
	for (int _y = 0; _y < 40; _y++)
	{
		for (int _x = 0; _x < 60; _x++)
		{
			if (nullptr != Tiles[_y][_x].SpriteRenderer) {

				if (_y >= 1 && _x >= 1 && _y <= 38 && _x <= 58)
				{
					//	현재타일이름
					std::string SpriteName = Tiles[_y][_x].SpriteRenderer->GetCurSpriteName();
					int FindIndex = SpriteName.find('_');
					std::string TypeName = SpriteName.substr(FindIndex);
					if ("_GROUND.PNG" == TypeName) 
					{
						AllTileTypes[_y][_x] = TILETYPE::GROUND;
					}
					else if ("_WALL.PNG" == TypeName)
					{
						AllTileTypes[_y][_x] = TILETYPE::WALL;
					}

					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (0 <= _y + i && 0 <= _x + j && 60 > _x + j && 40 > _y + i) {

							}
							std::string CompareName = Tiles[_y + i][_x + j].SpriteRenderer->GetCurSpriteName();
							//	주위타일과 타일이름을 비교해서 키값생성
							if (SpriteName == CompareName) {
								FindKey += "1";
							}
							else if (SpriteName != CompareName) {
								FindKey += "0";
							}
						}
					}
					int SpriteIndex = PMDContentsCore::GetTileIndex(FindKey);
					Tiles[_y][_x].SpriteRenderer->SetSprite(SpriteName, SpriteIndex);
				}
			}
		}
	}
}

void ATileMap::CheckTile()
{

}

TILETYPE ATileMap::GetTileType(int _x, int _y)
{
	return AllTileTypes[_x][_y];
}



