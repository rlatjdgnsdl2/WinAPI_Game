#include "PreCompile.h"
#include "Dungeon.h"

#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "PMDContentsCore.h"


ADungeon::ADungeon() 
{

}

ADungeon::~ADungeon() 
{

}

void ADungeon::SetAllWall()
{
	for (int _y = 0; _y < DungeonData.DungeonSize.Y; _y++)
	{
		for (int _x = 0; _x < DungeonData.DungeonSize.X; _x++)
		{
			SetTile(_x, _y, DungeonData.CurDungeonName +"_Wall.png");
		}
	}
}

void ADungeon::SetBorderWall()
{
	for (int y = 0; y < DungeonData.DungeonSize.Y; y++)
	{
		for (int x = 0; x < DungeonData.DungeonSize.X; x++)
		{
			if (y <= 2 || x <= 2 || y >= DungeonData.DungeonSize.Y - 3 || x >= DungeonData.DungeonSize.X - 3)
			{
				//	가장자리는 벽으로
				SetTile(x, y, DungeonData.CurDungeonName + "_Wall.png");
			}
		}
	}
}

void ADungeon::SetNaturally()
{
	for (int y = 0; y < DungeonData.DungeonSize.Y; y++)
	{
		for (int x = 0; x < DungeonData.DungeonSize.X; x++)
		{
			if (nullptr != Tiles[y][x].SpriteRenderer)
			{
				//	현재타일이름
				std::string SpriteName = Tiles[y][x].SpriteRenderer->GetCurSpriteName();
				int FindIndex = SpriteName.find('_');
				std::string TypeName = SpriteName.substr(FindIndex);
				if ("_GROUND.PNG" == TypeName)
				{
					DungeonData.TileTypes[y][x] = TILETYPE::GROUND;
				}
				else if ("_WALL.PNG" == TypeName)
				{
					DungeonData.TileTypes[y][x] = TILETYPE::WALL;
				}
				else if ("_WATER.PNG" == TypeName)
				{
					DungeonData.TileTypes[y][x] = TILETYPE::WATER;
				}

				if (y >= 1 && x >= 1 && y <= DungeonData.DungeonSize.Y - 2 && x <= DungeonData.DungeonSize.X - 2)
				{
					//	타일세팅
					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (0 <= y + i && 0 <= x + j && DungeonData.DungeonSize.X > x + j && DungeonData.DungeonSize.Y > y + i)
							{
								//	주위타일과 타일이름을 비교해서 키값생성
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


