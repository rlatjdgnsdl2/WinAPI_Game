#include "PreCompile.h"
#include "TitleGameMode.h"

#include "TitleAnimActor.h"
#include "TitleBackground.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>

float ATitleGameMode::TitlePlayTime = 0.0f;

ATitleGameMode::ATitleGameMode()
{
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();
	ATitleBackground* Background = GetWorld()->SpawnActor<ATitleBackground>();
	ATitleAnimActor* AnimCharacter = GetWorld()->SpawnActor<ATitleAnimActor>();
	GetWorld()->SetCameraToMainPawn(false);
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	TitlePlayTime += _DeltaTime;
	if (true == UEngineInput::GetInst().IsDown('G'))
	{
		UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
	}
}

void ATitleGameMode::LevelChangeEnd()
{
	ResetTitlePlayTime();
}

float ATitleGameMode::GetTitlePlayTime()
{
	return TitlePlayTime;
}

void ATitleGameMode::ResetTitlePlayTime()
{
	TitlePlayTime = 0.0f;
}




