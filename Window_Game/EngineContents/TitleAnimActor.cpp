#include "PreCompile.h"
#include "TitleAnimActor.h"
#include "TitleActor.h"

#include <EngineCore/EngineSprite.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/SpriteRenderer.h>



ATitleAnimActor::ATitleAnimActor()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	SpriteRenderer->SetSprite("1.Intro_anim.png");
	SpriteRenderer->SetComponentScale(SpriteRenderer->GetComponentScale());
	SpriteRenderer->CreateAnimation("IntroAnim", "1.Intro_Anim.png", 0, 14, 0.1f, false);
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}
ATitleAnimActor::~ATitleAnimActor()
{

}

void ATitleAnimActor::BeginPlay()
{
	SetActorLocation({ 300,300 });
}

void ATitleAnimActor::Tick(float _DeltaTime)
{
	test += _DeltaTime;
	Super::Tick(_DeltaTime);
	SpriteRenderer->ChangeAnimation("IntroAnim");
	if (test < 1.0f)
	{
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * 200.f);

	}
	else if (test > 1.0f && test < 1.5f)
	{
		AddActorLocation(FVector2D::LEFT * _DeltaTime * 800.f);
		AddActorLocation(FVector2D::UP * _DeltaTime * 300.f);
	}




}
