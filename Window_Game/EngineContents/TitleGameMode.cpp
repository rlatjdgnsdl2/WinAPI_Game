#include "PreCompile.h"
#include "TitleGameMode.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>

#include "TitleAnim.h"
#include "TitleLogo.h"
#include "TitleBackground.h"
#include "Fade.h"
#include "TitlePetal.h"

#include <EngineCore/SpriteRenderer.h>


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
	Fade->FadeOut();
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();
	TitleBackGround = GetWorld()->SpawnActor<ATitleBackground>();
	TitleAnim = GetWorld()->SpawnActor<ATitleAnim>();
	TitleAnim->GetSpriteRenderer()->SetSpriteScale(0.0f);
	TitleLogo = GetWorld()->SpawnActor<ATitleLogo>();
	TitleLogo->SetActive(false);
	GetWorld()->SetCameraToMainPawn(false);
	Fade = GetWorld()->SpawnActor<AFade>();
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	TitlePlayTime += _DeltaTime;
	CurDuration += _DeltaTime;
	// Space누르면 다음레벨
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		Fade->FadeIn();
		IsNextLevel = true;
	}
	// 타이틀 배경 움직임
	if (2.5f < TitlePlayTime && TitlePlayTime < 8.2f) {
		TitleBackGround->AddActorLocation(FVector2D::UP * _DeltaTime * 200.f);
	}
	// 타이틀 애니메이션
	if (TitlePlayTime > 7.0f && TitlePlayTime < 8.5f) {
		CurDuration += _DeltaTime;
		TitleAnim->PlayAnimation(_DeltaTime);
		float Value = UEngineMath::Clamp(CurDuration, 0.0f, 1.0f);
		TitleAnim->GetSpriteRenderer()->SetSpriteScale(Value);
		TitleAnim->AddActorLocation(UpPower * _DeltaTime);
		UpPower += FVector2D::UP * _DeltaTime * 150.0f;
		TitleAnim->AddActorLocation(FVector2D::DOWN * _DeltaTime * 100.0f);
		TitleAnim->AddActorLocation(FVector2D::LEFT * _DeltaTime * 200.0f);
	}
	if (TitlePlayTime > 8.5f)
	{
		TitleAnim->AddActorLocation(UpPower * _DeltaTime);
		UpPower += FVector2D::UP * _DeltaTime * 150.0f;
		TitleAnim->AddActorLocation(FVector2D::UP * _DeltaTime * 600.f);
		TitleAnim->AddActorLocation(FVector2D::LEFT * _DeltaTime * 1000.f);
	}
	if (TitlePlayTime > 8.5f) {
		if (IsPetals == false)
		{
			SpawnPetals();
			IsPetals = true;
		}
	}

	// 타이틀 배경
	if (12.0f < TitlePlayTime && TitlePlayTime < 14.0f) {
		TitleBackGround->AddActorLocation(FVector2D::DOWN * _DeltaTime * 200.f);
		TitleLogo->SetActive(true);
	}
	if (IsNextLevel == true)
	{
		FadeTime += _DeltaTime;
		if (FadeTime > 2.0f)
		{
			UEngineAPICore::GetCore()->OpenLevel("CharacterSelectLevel");
		}
	}
}

void ATitleGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	TitleLogo->SetActive(false);
	FadeTime = 0.0f;
	TitlePlayTime = 0.0f;
	IsNextLevel = false;
	for (ATitlePetal* Petal : PetalList)
	{
		Petal->Destroy();
	}
}


void ATitleGameMode::SpawnPetals()
{
	for (int i = 0; i < 10; i++)
	{
		int RandomX = Random.RandomInt(300, 800); 
		int RandomY = Random.RandomInt(700, 1000); 
		ATitlePetal* NewPetal = GetWorld()->SpawnActor<ATitlePetal>(FVector2D({ RandomX, RandomY }));
		NewPetal->SetSmall(true);
		PetalList.push_back(NewPetal);
	}
	for (int i = 0; i < 10; i++)
	{
		int RandomX = Random.RandomInt(300, 800);
		int RandomY = Random.RandomInt(1000, 1300);
		ATitlePetal* NewPetal = GetWorld()->SpawnActor<ATitlePetal>(FVector2D({ RandomX, RandomY }));
		NewPetal->SetSmall(true);
		PetalList.push_back(NewPetal);
	}
	for (int i = 0; i < 10; i++)
	{
		int RandomX = Random.RandomInt(300, 800);
		int RandomY = Random.RandomInt(1300, 1600);
		ATitlePetal* NewPetal = GetWorld()->SpawnActor<ATitlePetal>(FVector2D({ RandomX, RandomY }));
		NewPetal->SetSmall(true);
		PetalList.push_back(NewPetal);
	}

	for (int i = 0; i < 10; i++)
	{
		int RandomX = Random.RandomInt(300, 800); 
		int RandomY = Random.RandomInt(700, 1000);
		ATitlePetal* NewPetal = GetWorld()->SpawnActor<ATitlePetal>(FVector2D({ RandomX, RandomY }));
		NewPetal->SetSmall(false);
		PetalList.push_back(NewPetal);
	}
	for (int i = 0; i < 10; i++)
	{
		int RandomX = Random.RandomInt(300, 800);
		int RandomY = Random.RandomInt(1000, 1300);
		ATitlePetal* NewPetal = GetWorld()->SpawnActor<ATitlePetal>(FVector2D({ RandomX, RandomY }));
		NewPetal->SetSmall(false);
		PetalList.push_back(NewPetal);
	}
	for (int i = 0; i < 10; i++)
	{
		int RandomX = Random.RandomInt(300, 800);
		int RandomY = Random.RandomInt(1300, 1600);
		ATitlePetal* NewPetal = GetWorld()->SpawnActor<ATitlePetal>(FVector2D({ RandomX, RandomY }));
		NewPetal->SetSmall(false);
		PetalList.push_back(NewPetal);
	}
}






