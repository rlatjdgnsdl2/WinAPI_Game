#include "PreCompile.h"
#include "SpecialSkill.h"

#include <EngineCore/SpriteRenderer.h>

ASpecialSkill::ASpecialSkill() 
{
	
	

}

ASpecialSkill::~ASpecialSkill() 
{

}

void ASpecialSkill::BeginPlay()
{
	Super::BeginPlay();
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Water_Bomb", 0);
	
	FVector2D Scale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation({ 0.0f,Scale.Y/3.0f *-1.0f});
	SpriteRenderer->SetOrder(ERenderOrder::ATTACK_Player);
	float Frame = 1.0f / 8.0f;
	SpriteRenderer->CreateAnimation("Water_Bomb", "Water_Bomb", 0, 7, Frame, false);

}

void ASpecialSkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SpriteRenderer->ChangeAnimation("Water_Bomb");
}

bool ASpecialSkill::IsAttack()
{
	return false == SpriteRenderer->IsCurAnimationEnd();
}




