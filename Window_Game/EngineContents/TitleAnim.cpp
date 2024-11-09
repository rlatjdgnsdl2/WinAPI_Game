#include "PreCompile.h"
#include "TitleAnim.h"

#include <EngineCore/EngineSprite.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/SpriteRenderer.h>




ATitleAnim::ATitleAnim()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	SpriteRenderer->SetSprite("1.Intro_anim.png");
	SpriteRenderer->CreateAnimation("IntroAnim", "1.Intro_Anim.png", 0, 14);
	
}
ATitleAnim::~ATitleAnim()
{

}



void ATitleAnim::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({ 600,300 });
	FVector2D AnimCharactor = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(AnimCharactor.Half());
}



void ATitleAnim::PlayAnimation(float _DeltaTime)
{
	
}






