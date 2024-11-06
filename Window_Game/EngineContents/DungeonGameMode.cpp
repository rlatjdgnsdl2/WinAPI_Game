#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "Dungeon.h"

ADungeon* ADungeonGameMode::Dungeon;

ADungeonGameMode::ADungeonGameMode()
{

}

ADungeonGameMode::~ADungeonGameMode()
{

}

void ADungeonGameMode::BeginPlay()
{
	Super::BeginPlay();
}
void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::GetInst().IsDown('G'))
	{
		UEngineAPICore::GetCore()->OpenLevel("TitleLevel");
	}
}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	if (nullptr == Dungeon) {

		Dungeon = GetWorld()->SpawnActor<ADungeon>();
	}
	Dungeon->SetDungeonName("BeachCave");
	GenerateDungeon();
}

void ADungeonGameMode::LevelChangeEnd()
{

}


void ADungeonGameMode::GenerateDungeon()
{
	Dungeon->SliceDungeon();
	Dungeon->SetAllWall();

	Dungeon->SetRoom();
	Dungeon->SetHallWay();


	Dungeon->SetBorderWall();
	Dungeon->SetNaturally();
}











