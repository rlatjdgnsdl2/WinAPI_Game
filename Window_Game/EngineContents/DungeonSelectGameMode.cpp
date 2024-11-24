#include "PreCompile.h"
#include "DungeonSelectGameMode.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/EngineCoreDebug.h>



#include "Box.h"
#include "Text.h"
#include "Fade.h"
#include "GameDataManager.h"


ADungeonSelectGameMode::ADungeonSelectGameMode()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation(WindowSize.Half());
	WorldMapRenderer = CreateDefaultSubObject<USpriteRenderer>();
	WorldMapRenderer->SetSprite("WorldMap.png");
	FVector2D Size = WorldMapRenderer->SetSpriteScale(0.5f);
	WorldMapRenderer->SetOrder(ERenderOrder::BackGround);
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

	DungeonNameRenderer->SetString(DungeonMapStartIter->first, Color::Green);

}

void ADungeonSelectGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	{
		AFade* Actor = GetWorld()->SpawnActor<AFade>();
		Actor->FadeOut();
		Fade = Actor;
	}
}

void ADungeonSelectGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	CurDuration = 0.0f;
	IsNextLevel = false;
}

void ADungeonSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector2D MousePos = UEngineAPICore::GetCore()->GetMainWindow().GetMousePos();
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.X));
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.Y));
	DungeonNameRenderer->ShowText(0.0f);

	if (true == UEngineInput::GetInst().IsDown(VK_LEFT))
	{
		if (DungeonMapStartIter == DungeonMaps.begin()) {
			DungeonMapStartIter = DungeonMaps.end();
		}
		DungeonMapStartIter--;
		GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
		DungeonNameRenderer->SetString(DungeonMapStartIter->first, Color::Green);
	}
	if (true == UEngineInput::GetInst().IsDown(VK_RIGHT))
	{
		DungeonMapStartIter++;
		if (DungeonMapStartIter == DungeonMapEndIter) {
			DungeonMapStartIter = DungeonMaps.begin();
		}
		GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
		DungeonNameRenderer->SetString(DungeonMapStartIter->first, Color::Green);
	}
	//	던전입장
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		UGameDataManager::GetInst().SetSelectDungeon(DungeonMapStartIter->first);
		IsNextLevel = true;
		Fade->FadeIn();
	}

	if (IsNextLevel == true)
	{
		CurDuration += _DeltaTime;
		if (CurDuration > 2.0f) {
			UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");

		}
	}
}



