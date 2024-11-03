#include "PreCompile.h"
#include "DungeonGenerator.h"

#include "Dungeon.h"



UDungeonGenerator::UDungeonGenerator() 
{

}
UDungeonGenerator::~UDungeonGenerator() 
{
	Dungeon = nullptr;
}

void UDungeonGenerator::GenerateDungeon(class ADungeon* _Dungeon)
{
	Dungeon = _Dungeon;
	SetAllWall();
	SetRandomSizeRoom();
	SetRandomHallWay();
}

void UDungeonGenerator::SetAllWall()
{
	Dungeon->SetAllWall();
}
