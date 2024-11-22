#include "PreCompile.h"
#include "TitleAnim.h"

#include <EngineCore/EngineSprite.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/SpriteRenderer.h>




ATitleAnim::ATitleAnim()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::Player);
	SpriteRenderer->SetSprite("Title_anim.png");
	float frame = 2.0f / 15;
	SpriteRenderer->CreateAnimation("TitleAnim", "Title_Anim.png", 0, 14, frame, false);
}
ATitleAnim::~ATitleAnim()
{

}



void ATitleAnim::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({ 500,200 });
	FVector2D AnimCharactor = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(AnimCharactor.Half());
}



void ATitleAnim::PlayAnimation(float _DeltaTime)
{
	SpriteRenderer->ChangeAnimation("TitleAnim");
}






