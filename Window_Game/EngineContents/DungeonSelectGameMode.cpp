#include "PreCompile.h"
#include "DungeonSelectGameMode.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/EngineCoreDebug.h>




#include "GameDataManager.h"


ADungeonSelectGameMode::ADungeonSelectGameMode()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation(WindowSize.Half());
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("WorldMap.png");
	FVector2D Size = SpriteRenderer->SetSpriteScale(0.5f);
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
}

ADungeonSelectGameMode::~ADungeonSelectGameMode()
{

}


void ADungeonSelectGameMode::BeginPlay()
{
	Super::BeginPlay();
	DungeonMaps.insert({"BeachCave",FVector2D({298,269}) });
	DungeonMapStartIter = DungeonMaps.begin();
	DungeonMapEndIter = DungeonMaps.end();
	GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
	GetWorld()->SetCameraToMainPawn(false);
}

void ADungeonSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector2D MousePos = UEngineAPICore::GetCore()->GetMainWindow().GetMousePos();
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.X));
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.Y));
	if (true == UEngineInput::GetInst().IsDown('A'))
	{
		if (DungeonMapStartIter == DungeonMaps.begin()) {
			DungeonMapStartIter = DungeonMaps.end();
		}
		DungeonMapStartIter--;
		GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
	}
	if (true == UEngineInput::GetInst().IsDown('D'))
	{
		DungeonMapStartIter++;
		if (DungeonMapStartIter == DungeonMapEndIter) {
			DungeonMapStartIter = DungeonMaps.begin();
		}
		GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
	}
	//	던전입장
	if (true == UEngineInput::GetInst().IsDown('G')) {
		UGameDataManager::GetInst().SetSelectDungeon(DungeonMapStartIter->first);
		UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
	}
}



