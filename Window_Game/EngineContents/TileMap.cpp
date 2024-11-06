#include "PreCompile.h"
#include "TileMap.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineCoreDebug.h>

#include "DungeonGameMode.h"
#include "PMDContentsCore.h"



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
	Tiles[_y][_x].SpriteRenderer->SetSprite(_SpriteName, 4);
	Tiles[_y][_x].SpriteRenderer->SetComponentLocation({ (_x)*_Scale.X,(_y)*_Scale.Y });
	Tiles[_y][_x].SpriteRenderer->SetSpriteScale(1.0f);
	Tiles[_y][_x].SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	FVector2D TileLocation = Tiles[_y][_x].SpriteRenderer->GetComponentLocation();
	Tiles[_y][_x].TileTrans = FTransform(_Scale, TileLocation);
}



void ATileMap::SetTile(int _col, int _row, std::string_view _SpriteName)
{
	Tiles[_row][_col].SpriteRenderer->SetSprite(_SpriteName.data(), 4);
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

void ATileMap::LevelChangeStart()
{
}






void ATileMap::SetHallWay()
{
	UEngineRandom random;
	FIntPoint PreAnchor = FIntPoint(random.RandomInt(BoderSize, DungeonSize.X - BoderSize - 1), random.RandomInt(BoderSize, DungeonSize.Y - BoderSize - 1));;
	AllGround.push_back(PreAnchor);

	for (int j = 0; j < 10; j++)
	{
		FIntPoint Anchor = FIntPoint(random.RandomInt(BoderSize, DungeonSize.X - BoderSize - 1), random.RandomInt(BoderSize, DungeonSize.Y - BoderSize - 1));
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
				AllGround.push_back(FIntPoint(Anchor.X + i, Anchor.Y));
			}
		}
		//	pre가 왼쪽에 있다면
		else if (Distance.X < 0) {
			for (int i = 0; i > Distance.X; i--)
			{
				SetTile(Anchor.X + i, Anchor.Y + Distance.Y, "_Ground.png");
				AllGround.push_back(FIntPoint(Anchor.X + i, Anchor.Y));
			}
		}
		PreAnchor = Anchor;
	}

}

bool ATileMap::IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms) {
	const int padding = 3; // 최소 간격
	for (const auto& room : rooms) {
		FIntPoint roomPos(room.Location.X, room.Location.Y);
		FIntPoint roomSize(room.Scale.X, room.Scale.Y);

		// 각 방의 경계를 패딩만큼 확장
		if (!(pos.X + size.X + padding <= roomPos.X || pos.X >= roomPos.X + roomSize.X + padding ||
			pos.Y + size.Y + padding <= roomPos.Y || pos.Y >= roomPos.Y + roomSize.Y + padding)) {
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
			DungeonData.Rooms.push_back(roomTransform);
		}
	}
}









