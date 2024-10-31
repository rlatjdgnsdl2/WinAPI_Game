#include "PreCompile.h"
#include "DungeonGenAlgorithm.h"
#include "Dungeon.h"



UDungeonGenAlgorithm::UDungeonGenAlgorithm() {};
UDungeonGenAlgorithm::~UDungeonGenAlgorithm() {};

void UDungeonGenAlgorithm::GenerateDungeon(ADungeon& _Dungeon)
{
	InitProcess(_Dungeon);
	SliceProcess(_Dungeon);
	RoomGenProcess(_Dungeon);
}

void UDungeonGenAlgorithm::InitProcess(ADungeon& _Dungeon)
{

}

