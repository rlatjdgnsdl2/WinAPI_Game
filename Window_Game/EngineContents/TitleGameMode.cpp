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
	if (2.5f < TitlePlayTime && TitlePlayTime < 8.2f) {
		TitleBackGround->AddActorLocation(FVector2D::UP * _DeltaTime * 200.f);
	}
	if (TitlePlayTime > 5.0f && TitlePlayTime < 7.0f) {
		TitleAnim->PlayAnimation(_DeltaTime);
		TitleAnim->AddActorLocation((FVector2D({ -1.5f, 1.0f }) + LeftAcceleration + UpAcceleration) * _DeltaTime * 100.0f);
	}
	if (TitlePlayTime > 7.0f) {
		TitleAnim->PlayAnimation(_DeltaTime);
		TitleAnim->AddActorLocation((FVector2D({ -2.5f, -1.5f }) + LeftAcceleration + UpAcceleration) * _DeltaTime * 100.0f);
	}


}

void ATitleGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	TitlePlayTime = 0.0f;
}






