#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "TileMap.h"

ATileMap* ADungeonGameMode::Dungeon;

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

		Dungeon = GetWorld()->SpawnActor<ATileMap>();
	}
	GenerateDungeon();
	AActor* CurPlayer = GetWorld()->GetPawn();
	/*Player = dynamic_cast<APlayer>(CurPlayer);
	DungeonData = Dungeon->GetDungeonData();*/
}

void ADungeonGameMode::LevelChangeEnd()
{

}


void ADungeonGameMode::GenerateDungeon()
{
	Dungeon->SetAllWall();

	Dungeon->SetHallWay();
	Dungeon->SetRoom();


	Dungeon->SetBorderWall();
	Dungeon->SetNaturally();
}



void ADungeonGameMode::SetCurDungeonName(std::string_view _DungeonName)
{
	CurDungeonName = _DungeonName;
}







