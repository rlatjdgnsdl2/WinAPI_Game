#include "PreCompile.h"
#include "TileMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

#include "PMDContentsCore.h"

ATileMap::ATileMap()
{
	TileMap.resize(40, std::vector<USpriteRenderer*>(60, nullptr));
	UImageManager::GetInst().CuttingSprite("BeachCave_Ground.png", 5, 10);
	UImageManager::GetInst().CuttingSprite("BeachCave_Wall.png", 5, 10);


}

ATileMap::~ATileMap()
{

}

void ATileMap::BeginPlay()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			TileMap[y][x] = CreateTile(x, y, "BeachCave_Wall.png");
		}
	}
}

void ATileMap::Tick(float _DeltaTime)
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
		SetTile(testNumX, testNumY, "BeachCave_Ground.png");
	}

	if (UEngineInput::GetInst().IsDown('Y')) {
		CheckTile("BeachCave_Ground.png");
	}
}

USpriteRenderer* ATileMap::CreateTile(int _col, int _row, std::string_view _SpriteName)
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite(_SpriteName, 0);
	SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation({ _col * 72,_row * 72 });
	return SpriteRenderer;
}

void ATileMap::SetTile(int _col, int _row, std::string_view _SpriteName)
{
	TileMap[_row][_col]->SetSprite(_SpriteName, 0);
}

void ATileMap::CheckTile(std::string_view _SpriteName)
{

	for (int _y = 0; _y < 40; _y++)
	{
		for (int _x = 0; _x < 60; _x++)
		{
			if (nullptr != TileMap[_y][_x]) {

				if (_y < 2 || _x < 2 || _y > 37 || _x > 57)
				{
					//	가장자리는 벽으로
					TileMap[_y][_x]->SetSprite("BeachCave_Wall.png", 4);
				}
				else
				{
					
					//	타일체크
					//	현재타일이름
					//std::string SpriteName = TileMap[_y][_x]->GetSpriteName();
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
					int SpriteIndex = 0;
					auto it = PMDContentsCore::TileIndexForKey.find(FindKey);
					if (it != PMDContentsCore::TileIndexForKey.end()) 
					{
						SpriteIndex = it->second;
					}
					else 
					{
						SpriteIndex = 4;
					}
					TileMap[_y][_x]->SetSprite(SpriteName, SpriteIndex);

				}
			}




		}
	}
}


