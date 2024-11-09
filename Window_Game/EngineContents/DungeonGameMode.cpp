#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "Dungeon_BSP.h"
#include "Partner.h"
#include "TurnManager.h"
#include "Enemy_01.h"


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
	//	带傈积己
	
	if (nullptr == Dungeon) {

		Dungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
	}
	Dungeon->Generate();
	//Dungeon->SetCurDungeonName("BeachCave");
	// 畔概聪历 积己
	if (nullptr == TurnManager) {
		TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	}
	TurnManager->SetDungeon(Dungeon);
	
	//	颇飘呈 积己
	if (nullptr == Partner) {
		Partner = GetWorld()->SpawnActor<APartner>();

	}
	TurnManager->SetPatner(Partner);

	//Test
	//AEnemy_01* NewEnemy = GetWorld()->SpawnActor<AEnemy_01>();
	//TurnManager->SetTestEnemy(NewEnemy);

}

void ADungeonGameMode::LevelChangeEnd()
{

}














