#include "PreCompile.h"
#include "TitleActor.h"
#include "ContentsEnum.h"
#include "TitleAnimActor.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>



ATitleActor::ATitleActor()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite("1.Intro_Bg.png");
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}

ATitleActor::~ATitleActor() {}

void ATitleActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SetCameraToMainPawn(false);

}

void ATitleActor::Tick(float _DeltaTime)
{
	test += _DeltaTime;
	Super::Tick(_DeltaTime);

	if (test > 4.3f)
	{
		return;
	}

	else if (test > 2.0f)
	{
		AddActorLocation(FVector2D::UP * _DeltaTime * 500.f);
	}

	if (test > 3.0f)
	{
		if (!IsPlayAnim) {

			ATitleAnimActor* NewActor = GetWorld()->SpawnActor<ATitleAnimActor>();
			IsPlayAnim = true;
		}
	}

}


