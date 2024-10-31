#include "PreCompile.h"
#include "DungeonManager.h"
#include "DungeonGenAlgorithm.h"


UDungeonManager::UDungeonManager() 
{
}
UDungeonManager::~UDungeonManager() 
{
	/*std::map<std::string, UDungeonGenAlgorithm*>::iterator StartIter = AlgoMaps.begin();
	std::map<std::string, UDungeonGenAlgorithm*>::iterator EndIter = AlgoMaps.end();
	for (;  StartIter!=EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}*/
}

void UDungeonManager::GenerateDungeon(UDungeonGenAlgorithm* _SelectAlgo)
{
	_SelectAlgo->GenerateDungeon(Dungeon);
}





	
