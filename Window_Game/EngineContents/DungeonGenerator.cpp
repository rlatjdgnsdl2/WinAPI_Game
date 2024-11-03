#include "PreCompile.h"
#include "DungeonGenerator.h"

#include "TileMap.h"



UDungeonGenerator::UDungeonGenerator() 
{

}
UDungeonGenerator::~UDungeonGenerator() 
{
	Dungeon = nullptr;
}

void UDungeonGenerator::GenerateDungeon(class ATileMap* _Dungeon)
{
	Dungeon = _Dungeon;
	AllSetWall();
}

void UDungeonGenerator::AllSetWall()
{
	Dungeon->
}
