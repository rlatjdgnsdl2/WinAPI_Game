#include "PreCompile.h"
#include "TitleGameMode.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>

#include "TitleAnim.h"
#include "TitleLogo.h"
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
	BGMPlayer = UEngineSound::Play("TitleBGM.mp3");
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();
	TitleBackGround = GetWorld()->SpawnActor<ATitleBackground>();
	TitleAnim = GetWorld()->SpawnActor<ATitleAnim>();
	TitleLogo = GetWorld()->SpawnActor<ATitleLogo>();
	TitleLogo->SetActive(false);	
	GetWorld()->SetCameraToMainPawn(false);
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	TitlePlayTime += _DeltaTime;
	// Space누르면 다음레벨
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("CharacterSelectLevel");
	}
	// 타이틀 배경 움직임
	if (2.5f < TitlePlayTime && TitlePlayTime < 8.2f) {
		TitleBackGround->AddActorLocation(FVector2D::UP * _DeltaTime * 200.f);
	}
	// 타이틀 애니메이션
	if (TitlePlayTime > 5.0f && TitlePlayTime < 7.0f) {
		TitleAnim->PlayAnimation(_DeltaTime);
		TitleAnim->AddActorLocation((FVector2D({ -1.5f, 1.0f }) + LeftAcceleration + UpAcceleration) * _DeltaTime * 100.0f);
	}
	if (TitlePlayTime > 7.0f) {
		TitleAnim->PlayAnimation(_DeltaTime);
		TitleAnim->AddActorLocation((FVector2D({ -2.5f, -1.5f }) + LeftAcceleration + UpAcceleration) * _DeltaTime * 100.0f);
	}
	if (10.0f < TitlePlayTime && TitlePlayTime < 12.0f) {
		TitleBackGround->AddActorLocation(FVector2D::DOWN * _DeltaTime * 200.f);
		TitleLogo->SetActive(true);
	}


}

void ATitleGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	TitleLogo->SetActive(false);
	TitlePlayTime = 0.0f;
	
}






