#include "PreCompile.h"
#include "TileMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

#include "PMDContentsCore.h"

ATileMap::ATileMap()
{
	Tiles.resize(TileCount.Y, std::vector<Tile>(TileCount.X));
}
ATileMap::~ATileMap()
{

}
void ATileMap::BeginPlay()
{
	Super::BeginPlay();
	InitTileMap();
	SetActorLocation({ 0,0 });
}



void ATileMap::SetTileMapData(std::string_view _CurDungeonName, FIntPoint _Count, FVector2D _TileSize)
{
	CurDungeonName = _CurDungeonName;
	TileCount = _Count;
	TileSize = _TileSize;
	Tiles.resize(TileCount.Y, std::vector<Tile>(TileCount.X));
	SetActorLocation({ 0,0 });	
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
		CheckTile();
	}
	
}





void ATileMap::InitTileMap()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			CreateTile(x, y, FVector2D(72, 72), CurDungeonName + "_Wall.png");
		}
	}
}

void ATileMap::SetTile(int _col, int _row, std::string_view _TileType)
{
	if (0 <= _col && 0 <= _row && 60 > _col && 40 > _row) {

		Tiles[_row][_col].SpriteRenderer->SetSprite(CurDungeonName + _TileType.data(), 4);
		Tiles[_row][_col].SpriteRenderer->SetSpriteScale();
	}
}


void ATileMap::CheckTile()
{
	for (int _y = 0; _y < 40; _y++)
	{
		for (int _x = 0; _x < 60; _x++)
		{
			if (nullptr != Tiles[_y][_x].SpriteRenderer) {

				if (_y < 2 || _x < 2 || _y > 37 || _x > 57)
				{
					//	가장자리는 벽으로
					Tiles[_y][_x].SpriteRenderer->SetSprite(CurDungeonName + "_Wall.png", 4);
				}
				else
				{
					//	타일체크
					//	현재타일이름
					std::string SpriteName = Tiles[_y][_x].SpriteRenderer->GetCurSpriteName();


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



