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
void ADungeonGameMode::GenerateDungeon(UDungeonGenAlgorithm* _SelectAlgo)
{
	_SelectAlgo->GenerateDungeon(Dungeon);
}
