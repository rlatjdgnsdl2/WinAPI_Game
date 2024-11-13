#include "PreCompile.h"
#include "DungeonSelectGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include "GameDataManager.h"


ADungeonSelectGameMode::ADungeonSelectGameMode()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("WorldMap.png");
	/*SpriteRenderer->SetSpriteScale(0.7f);
	SetActorLocation({ 0,0 });
	FVector2D SpriteScale = SpriteRenderer->GetSpriteScale();
	SpriteRenderer->SetComponentLocation(SpriteScale * 0.35f);
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);*/
}

ADungeonSelectGameMode::~ADungeonSelectGameMode()
{

}


void ADungeonSelectGameMode::BeginPlay()
{
	Super::BeginPlay();
	DungeonMaps.insert({ "BeachCave",FVector2D({410,327}) });
	DungeonMaps.insert({ "AmpPlains",FVector2D({730,394}) });

	DungeonMapStartIter = DungeonMaps.begin();
	DungeonMapEndIter = DungeonMaps.end();

	GetWorld()->GetPawn()->SetActorLocation(DungeonMapStartIter->second);
	GetWorld()->SetCameraToMainPawn(true);
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);


}

void ADungeonSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

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

	if (true == UEngineInput::GetInst().IsDown('G')) {
		UGameDataManager::GetInst().SetSelectDungeon(DungeonMapStartIter->first);
		UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
	}

}

void ADungeonSelectGameMode::SetCamera()
{

}


