#include "PreCompile.h"
#include "DungeonManager.h"
#include "DungeonGenAlgorithm.h"


UDungeonManager::UDungeonManager() {}
UDungeonManager::~UDungeonManager() {}

void UDungeonManager::GenerateDungeon(UDungeonGenAlgorithm* _SelectAlgo)
{
	_SelectAlgo->GenerateDungeon(Dungeon);
}





	
