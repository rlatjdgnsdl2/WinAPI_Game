#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>

#include "Dungeon.h"
#include "DungeonGenerator.h"
ADungeonGameMode::ADungeonGameMode() 
{

}

ADungeonGameMode::~ADungeonGameMode() 
{

}
void ADungeonGameMode::BeginPlay() 
{
	Super::BeginPlay();
	Dungeon = GetWorld()->SpawnActor<ADungeon>();
	
}

void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeEnd();
	GenerateDungeon(CurDungeonName,CurGeneratorName);
	
}

void ADungeonGameMode::GenerateDungeon(std::string_view _DungeonName, std::string_view _GeneratorName)
{
	UDungeonGenerator* DungeonGenerator = GeneratorMaps[_GeneratorName.data()];
	DungeonGenerator->GenerateDungeon(Dungeon);
}
