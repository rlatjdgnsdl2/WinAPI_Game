#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>



APokemon::APokemon() 
{

}
APokemon::~APokemon() 
{

}




void APokemon::Idle()
{
	SpriteRenderer->ChangeAnimation("IdleAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClimp(StartLocation, TargetLocation, CurDuration * 2.0f);
	SetActorLocation(NewLocation);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Skill(SkillType _SkillType)
{
	SpriteRenderer->ChangeAnimation("AttackAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
}
