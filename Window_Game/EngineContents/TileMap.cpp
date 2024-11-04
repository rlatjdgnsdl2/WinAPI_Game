#include "PreCompile.h"
#include "TileMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

#include "PMDContentsCore.h"

ATileMap::ATileMap()
{
	Tiles.resize(40, std::vector<Tile>(60));
}
ATileMap::~ATileMap()
{

}
void ATileMap::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation({ 0,0 });
	//	다 벽으로
	InitTileMap();
}

USpriteRenderer* ATileMap::CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName)
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite(_SpriteName, 4);
	SpriteRenderer->SetComponentLocation({ (_x ) * _Scale.X,(_y ) * _Scale.Y });
	SpriteRenderer->SetSpriteScale(1.0f);
	FVector2D TileLocation = SpriteRenderer->GetComponentLocation();
	Tiles[_y][_x].TileTrans = FTransform(_Scale, TileLocation - _Scale);
	return SpriteRenderer;
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
	if (UEngineInput::GetInst().IsDown('F'))
	{
		SetTile(testNumX, testNumY, "_Ground.png");
	}

	if (UEngineInput::GetInst().IsDown('Y')) {
		CheckTile();
	}
}


void ATileMap::SetTile(int _col, int _row, std::string_view _TileType)
{
	Tiles[_row][_col].TileMapRenderer->SetSprite(CurDungeonName + _TileType.data(), 0);
}

void ATileMap::InitTileMap()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			Tiles[y][x].TileMapRenderer = CreateTile(x, y, FVector2D(72, 72), CurDungeonName + "_Wall.png");
		}
	}
}

void ATileMap::CheckTile()
{
	for (int _y = 0; _y < 40; _y++)
	{
		for (int _x = 0; _x < 60; _x++)
		{
			if (nullptr != Tiles[_y][_x].TileMapRenderer) {

				if (_y < 2 || _x < 2 || _y > 37 || _x > 57)
				{
					//	가장자리는 벽으로
					Tiles[_y][_x].TileMapRenderer->SetSprite(CurDungeonName + "_Wall.png", 4);
				}
				else
				{
					//	타일체크
					//	현재타일이름
					std::string SpriteName = Tiles[_y][_x].TileMapRenderer->GetCurSpriteName();


					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							std::string CompareName = Tiles[_y + i][_x + j].TileMapRenderer->GetCurSpriteName();
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
					Tiles[_y][_x].TileMapRenderer->SetSprite(SpriteName, SpriteIndex);
				}
			}
		}
	}
}



