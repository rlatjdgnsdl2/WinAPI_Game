#include "PreCompile.h"
#include "Dungeon.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

#include "PMDContentsCore.h"

ADungeon::ADungeon()
{
	TileMap.resize(40, std::vector<USpriteRenderer*>(60, nullptr));

}

ADungeon::~ADungeon()
{

}
void ADungeon::BeginPlay()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			TileMap[y][x] = CreateTile(x, y, CurDungeonName + "_Ground.png");
		}
	}
}

USpriteRenderer* ADungeon::CreateTile(int _col, int _row, std::string_view _SpriteName)
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite(_SpriteName, 4);
	SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation({ _col * 72,_row * 72 });
	return SpriteRenderer;
}


void ADungeon::Tick(float _DeltaTime)
{
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
		//CheckTile("BeachCave_Ground.png");
		SetAllWall();
	}
}


void ADungeon::SetTile(int _col, int _row, std::string_view _TileType)
{
	TileMap[_row][_col]->SetSprite(CurDungeonName + _TileType.data(), 0);
}

void ADungeon::CheckTile(std::string_view _SpriteName)
{

	for (int _y = 0; _y < 40; _y++)
	{
		for (int _x = 0; _x < 60; _x++)
		{
			if (nullptr != TileMap[_y][_x]) {

				if (_y < 2 || _x < 2 || _y > 37 || _x > 57)
				{
					//	가장자리는 벽으로
					TileMap[_y][_x]->SetSprite(_SpriteName, 4);
				}
				else
				{
					//	타일체크
					//	현재타일이름
					std::string SpriteName = TileMap[_y][_x]->GetCurSpriteName();
					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{

							std::string CompareName = TileMap[_y + i][_x + j]->GetCurSpriteName();
							if (SpriteName == CompareName) {
								FindKey += "1";
							}
							else if (SpriteName != CompareName) {
								FindKey += "0";
							}
						}
					}
					int SpriteIndex = PMDContentsCore::GetTileIndex(FindKey);
					TileMap[_y][_x]->SetSprite(SpriteName, SpriteIndex);
				}
			}
		}
	}
}

void ADungeon::SetAllWall()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			TileMap[y][x]->SetSprite((CurDungeonName + "_Wall.png"), 4);
		}
	}
}

void ADungeon::SetRandomSizeRoom()
{

}

void ADungeon::SetRandomHallWay()
{

}


