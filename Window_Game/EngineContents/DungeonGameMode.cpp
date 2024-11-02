#include "PreCompile.h"
#include "DungeonGameMode.h"


#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>

#include "TileMap.h"
ADungeonGameMode::ADungeonGameMode() 
{

}

ADungeonGameMode::~ADungeonGameMode() 
{

}
void ADungeonGameMode::BeginPlay() 
{
	Super::BeginPlay();
	GetWorld()->SpawnActor<ATileMap>();
}

void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
