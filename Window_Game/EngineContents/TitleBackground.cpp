#include "PreCompile.h"
#include "TitleBackground.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

#include "ContentsEnum.h"
#include "TitleGameMode.h"


ATitleBackground::ATitleBackground()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite("1.Intro_Bg.png");
	
}

ATitleBackground::~ATitleBackground() {}

void ATitleBackground::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation({ 0,0 });
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}

void ATitleBackground::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({0,0});
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}



void ATitleBackground::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	float TitlePlayTime = ATitleGameMode::GetTitlePlayTime();
	
	if (TitlePlayTime > 2.0f && TitlePlayTime <4.3f)
	{
		AddActorLocation(FVector2D::UP * _DeltaTime * 500.f);
	}

	


}





