#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "GameDataManager.h"
#include "Dungeon_BSP.h"
#include "Partner.h"
#include "TurnManager.h"


ADungeonGameMode::ADungeonGameMode()
{

}

ADungeonGameMode::~ADungeonGameMode()
{
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
	UGameDataManager::GetInst().SetSelectDungeon("BeachCave");
	Dungeon->Generate(UGameDataManager::GetInst().GetSelectDungeon());

	// 畔概聪历 积己
	if (nullptr == TurnManager) {
		TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	}
	TurnManager->SetDungeon(Dungeon);
	

	//	利 积己
	if (nullptr == Enemy01) {
		Enemy01 = GetWorld()->SpawnActor<APokemon>("Kabuto");
		TurnManager->PushAllPokemon(Enemy01);
		TurnManager->PushEnemy(Enemy01);

	}
	if (nullptr == Enemy02) {
		Enemy02 = GetWorld()->SpawnActor<APokemon>("Corsola");
		TurnManager->PushAllPokemon(Enemy02);
		TurnManager->PushEnemy(Enemy02);
	}
	


}
















