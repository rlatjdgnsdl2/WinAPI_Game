#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "GameDataManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"
#include "TurnManager.h"
#include "DungeonUI.h"
#include "BasicUI.h"


ADungeonGameMode::ADungeonGameMode()
{

}

ADungeonGameMode::~ADungeonGameMode()
{

}

void ADungeonGameMode::BeginPlay()
{
	Super::BeginPlay();
	ATurnManager* TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	ADungeon_BSP* Dungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
	TurnManager->SetDungeon(Dungeon);
	TurnManager->SetPlayer(dynamic_cast<APlayer*>(GetWorld()->GetPawn()));

	ABasicUI* BasicUI = GetWorld()->SpawnActor<ABasicUI>();
	TurnManager->SetBasicUI(BasicUI);

	ADungeonUI* DungeonUI = GetWorld()->SpawnActor<ADungeonUI>();
	DungeonUI->SetDungeon(Dungeon);
	DungeonUI->SetBasicUI(BasicUI);
	TurnManager->SetDungeonUI(DungeonUI);
	DungeonUI->SetTurnManager(TurnManager);
	


}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	BGMPlayer = UEngineSound::Play(UGameDataManager::GetInst().GetSelectDungeon() + "BGM.mp3");
}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	BGMPlayer.Off();
}

void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector2D MousePos = UEngineAPICore::GetCore()->GetMainWindow().GetMousePos();
	/*UEngineDebug::CoreOutPutString(std::to_string(MousePos.X));
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.Y));*/
	if (true == UEngineInput::GetInst().IsDown('G'))
	{
		UEngineAPICore::GetCore()->OpenLevel("DungeonSelectLevel");
	}
}
























