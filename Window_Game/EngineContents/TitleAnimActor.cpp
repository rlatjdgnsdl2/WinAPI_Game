#include "PreCompile.h"
#include "TitleAnimActor.h"

#include <EngineCore/EngineSprite.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/SpriteRenderer.h>

#include "TitleGameMode.h"



ATitleAnimActor::ATitleAnimActor()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	SpriteRenderer->SetSprite("1.Intro_anim.png");
	SpriteRenderer->CreateAnimation("IntroAnim", "1.Intro_Anim.png", 0, 14, 0.1f, false);
	
}
ATitleAnimActor::~ATitleAnimActor()
{

}


void ATitleAnimActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation({ 300,300 });
	FVector2D AnimCharactor = SpriteRenderer->SetSpriteScale(0.0f);
	SpriteRenderer->SetComponentLocation(AnimCharactor.Half());
	
}
void ATitleAnimActor::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({ 400,300 });
	FVector2D AnimCharactor = SpriteRenderer->SetSpriteScale(0.0f);
	SpriteRenderer->SetComponentLocation(AnimCharactor.Half());
}

void ATitleAnimActor::LevelChangeEnd()
{
	IsAnimPlay = false;
}



void ATitleAnimActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	float TitlePlayTime = ATitleGameMode::GetTitlePlayTime();
	if (TitlePlayTime > 3.0f && TitlePlayTime < 4.0f)
	{
		if (!IsAnimPlay)
		{
			FVector2D ActorScale = SpriteRenderer->SetSpriteScale(1.0f);
			IsAnimPlay = true;
		}
		SpriteRenderer->ChangeAnimation("IntroAnim",true);
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * 200.f);

	}
	else if (TitlePlayTime > 4.0f && TitlePlayTime < 4.5f)
	{
		AddActorLocation(FVector2D::LEFT * _DeltaTime * 800.f);
		AddActorLocation(FVector2D::UP * _DeltaTime * 300.f);
	}
}


