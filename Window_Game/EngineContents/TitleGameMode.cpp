#include "PreCompile.h"
#include "TitleGameMode.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>

#include "TitleAnim.h"
#include "TitleBackground.h"


ATitleGameMode::ATitleGameMode()
{
	
}

ATitleGameMode::~ATitleGameMode()
{
}


void ATitleGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	if (TitleBackGround == nullptr) {
		TitleBackGround = GetWorld()->SpawnActor<ATitleBackground>();
	}
	if (TitleAnim == nullptr) {
		TitleAnim = GetWorld()->SpawnActor<ATitleAnim>();
	}

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
	if (2.5f<TitlePlayTime && TitlePlayTime< 6.3f) {
		TitleBackGround->AddActorLocation(FVector2D::UP * _DeltaTime * 300.f);
	}
	if (TitlePlayTime > 4.0f) {
		TitleAnim->PlayAnimation(_DeltaTime);
	}





}


void ATitleGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	TitlePlayTime = 0.0f;
}






