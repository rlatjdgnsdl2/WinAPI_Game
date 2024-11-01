#include "PreCompile.h"
#include "DungeonGameMode.h"
#include <EngineCore/EngineAPICore.h>
#include "DungeonGenAlgorithm.h"


ADungeonGameMode::ADungeonGameMode()
{

}
ADungeonGameMode::~ADungeonGameMode()
{

}

void ADungeonGameMode::BeginPlay()
{
	
}
void ADungeonGameMode::GenerateDungeon(std::string_view _SelectAlgo,Dungeon& _Dungeon);
{
	AlgoMaps[ _SelectAlgo.data()]->GenerateDungeon(_Dungeon);
}
