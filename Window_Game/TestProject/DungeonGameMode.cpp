#include "PreCompile.h"
#include "DungeonGameMode.h"
#include <EngineCore/EngineAPICore.h>
#include "DungeonGenAlgorithm.h"
#include "BasicAlgo.h"


ADungeonGameMode::ADungeonGameMode()
{
	UDungeonGenAlgorithm* BasicAlgo = new UBasicAlgo();
	AlgoMaps.insert({ "Basic",BasicAlgo });
}
ADungeonGameMode::~ADungeonGameMode()
{
	std::map<std::string, class UDungeonGenAlgorithm*>::iterator StartIter = AlgoMaps.begin();
	std::map<std::string, class UDungeonGenAlgorithm*>::iterator EndIter = AlgoMaps.end();
	for (; StartIter!=EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}
	AlgoMaps.clear();
}

void ADungeonGameMode::BeginPlay()
{
	
}

void ADungeonGameMode::GenerateDungeon(std::string_view _SelectAlgo)
{
	AlgoMaps[_SelectAlgo.data()]->GenerateDungeon(Dungeon);
}

