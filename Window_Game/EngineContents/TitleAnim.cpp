#include "PreCompile.h"
#include "TitleAnim.h"

#include <EngineCore/EngineSprite.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/SpriteRenderer.h>




ATitleAnim::ATitleAnim()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::Player);
	SpriteRenderer->SetSprite("Title_Anim.png");
	float frame = 1.5f / 15;
	SpriteRenderer->CreateAnimation("TitleAnim", "Title_Anim.png", 0, 14, frame, false);
}
ATitleAnim::~ATitleAnim()
{

}



void ATitleAnim::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({ 600,300 });
}



void ATitleAnim::PlayAnimation(float _DeltaTime)
{
	SpriteRenderer->ChangeAnimation("TitleAnim");
}






