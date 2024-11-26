#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>

#include "GameDataManager.h"



APokemon::APokemon()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
}

APokemon::~APokemon()
{

}
void APokemon::SetPokemon(std::string_view _PokemonName)
{
	//	스프라이트 세팅
	SpriteRenderer->SetSprite(GetName() + "_Idle.png");
	SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetOrder(ERenderOrder::Player);
	//	애니메이션 세팅
	SetAnim();
	//	능력치
	PokemonInfo = UGameDataManager::GetInst().GetPokemonAbility(_PokemonName);
}

void APokemon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void APokemon::Idle()
{
	SpriteRenderer->ChangeAnimation("IdleAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Skill()
{
	switch (CurSkill)
	{
	case SkillType::NormalAttack:
		NormalAttack();
		break;
	case SkillType::SpecialAttack:
		SpecialAttack();
		break;
	case SkillType::UseItem:
		break;
	default:
		break;
	}
}

void APokemon::Hurt()
{
	SpriteRenderer->ChangeAnimation("HurtAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Die(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	DeadDuration += _DeltaTime;
	SpriteRenderer->ChangeAnimation("HurtAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
	if (DeadDuration > 0.1f) {
		SpriteRenderer->SetActiveSwitch();
		DeadDuration = 0.0f;
	}
}


void APokemon::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration * MoveSpeed);
	SetActorLocation(NewLocation);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}












