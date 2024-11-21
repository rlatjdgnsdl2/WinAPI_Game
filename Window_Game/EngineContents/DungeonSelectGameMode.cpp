#include "PreCompile.h"
#include "DungeonSelectGameMode.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/EngineCoreDebug.h>



#include "Box.h"
#include "Text.h"
#include "GameDataManager.h"


ADungeonSelectGameMode::ADungeonSelectGameMode()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation(WindowSize.Half());
	WorldMapRenderer = CreateDefaultSubObject<USpriteRenderer>();
	WorldMapRenderer->SetSprite("WorldMap.png");
	FVector2D Size = WorldMapRenderer->SetSpriteScale(0.5f);
	WorldMapRenderer->SetOrder(ERenderOrder::BACKGROUND);
}

ADungeonSelectGameMode::~ADungeonSelectGameMode()
{

}


void ADungeonSelectGameMode::BeginPlay()
{
	Super::BeginPlay();
	DungeonMaps.insert({ "BeachCave",FVector2D({298,269}) });
	DungeonMaps.insert({ "DeepDarkCrater",FVector2D({131,150}) });
	DungeonMaps.insert({ "SurroundedSea",FVector2D({119,448}) });
	DungeonMaps.insert({ "AmpPlains",FVector2D({563,281}) });
	DungeonMapStartIter = DungeonMaps.begin();
	DungeonMapEndIter = DungeonMaps.end();
	GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
	GetWorld()->SetCameraToMainPawn(false);

	DungeonNameBox = GetWorld()->SpawnActor<ABox>();
	DungeonNameBox->SetActorLocation({ 210, 500 });
	DungeonNameBox->SetBoxSize({ 400.0f, 80.0f });

	DungeonNameRenderer = GetWorld()->SpawnActor<AText>();
	DungeonNameRenderer->SetActorLocation({ 300.0f, 520.0f });

	DungeonNameRenderer->SetString(DungeonMapStartIter->first, "Green");
	
}

void ADungeonSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector2D MousePos = UEngineAPICore::GetCore()->GetMainWindow().GetMousePos();
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.X));
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.Y));
	DungeonNameRenderer->ShowText(0.0f);

	if (true == UEngineInput::GetInst().IsDown('A'))
	{
		if (DungeonMapStartIter == DungeonMaps.begin()) {
			DungeonMapStartIter = DungeonMaps.end();
		}
		DungeonMapStartIter--;
		GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
		DungeonNameRenderer->SetString(DungeonMapStartIter->first, "Green");
	}
	if (true == UEngineInput::GetInst().IsDown('D'))
	{
		DungeonMapStartIter++;
		if (DungeonMapStartIter == DungeonMapEndIter) {
			DungeonMapStartIter = DungeonMaps.begin();
		}
		GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
		DungeonNameRenderer->SetString(DungeonMapStartIter->first, "Green");
	}
	//	던전입장
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		UGameDataManager::GetInst().SetSelectDungeon(DungeonMapStartIter->first);
		UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
	}
}



