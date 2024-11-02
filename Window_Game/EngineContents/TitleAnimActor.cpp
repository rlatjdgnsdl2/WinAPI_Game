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
	UImageManager::GetInst().CuttingSprite("1.Intro_anim.png", 5, 3);
	SpriteRenderer->SetSprite("1.Intro_anim.png");
	SpriteRenderer->CreateAnimation("IntroAnim", "1.Intro_Anim.png", 0, 14, 0.1f, false);
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale(0.0f);
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}
ATitleAnimActor::~ATitleAnimActor()
{

}

void ATitleAnimActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation({ 300,300 });
}

void ATitleAnimActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	float TitlePlayTime = ATitleGameMode::GetTitlePlayTime();
	if (TitlePlayTime > 3.0f && TitlePlayTime < 4.0f)
	{
		if (!IsAnimPlay)
		{
			FVector2D ActorScale = SpriteRenderer->SetSpriteScale();
			SpriteRenderer->SetComponentLocation(ActorScale.Half());
			IsAnimPlay = true;
		}
		SpriteRenderer->ChangeAnimation("IntroAnim");
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * 200.f);

	}
	else if (TitlePlayTime > 4.0f && TitlePlayTime < 4.5f)
	{
		SpriteRenderer->ChangeAnimation("IntroAnim");
		AddActorLocation(FVector2D::LEFT * _DeltaTime * 800.f);
		AddActorLocation(FVector2D::UP * _DeltaTime * 300.f);
	}

}
