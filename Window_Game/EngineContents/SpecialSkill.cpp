#include "PreCompile.h"
#include "SpecialSkill.h"

#include <EngineCore/SpriteRenderer.h>

ASpecialSkill::ASpecialSkill() 
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Water_Bomb.png",0);
	SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetOrder(ERenderOrder::ATTACK_Player);
	SpriteRenderer->CreateAnimation("Water_Bomb", "Water_Bomb.png",0,7,0.2f,false);

}

ASpecialSkill::~ASpecialSkill() 
{

}

void ASpecialSkill::BeginPlay()
{
	Super::BeginPlay();
}

void ASpecialSkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SpriteRenderer->ChangeAnimation("Water_Bomb");
	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		Destroy();
	}
}




