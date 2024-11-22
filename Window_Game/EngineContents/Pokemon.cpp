#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>

#include "GameDataManager.h"
#include "AbilityController.h"




APokemon::APokemon() :AbilityController(nullptr), SpriteRenderer(nullptr), CurDuration(0.0f), StartLocation(FVector2D::ZERO), TargetLocation(FVector2D::ZERO), CurSkill(SkillType::NormalAttack), TargetPokemon(nullptr), SpecialSkill(nullptr), IsAttackValue(false), IsHurtValue(false), CurLevel(0), CurMaxHp(0), CurHp(0), CurATK(0), CurSPD(0)
{
}

APokemon::~APokemon()
{

}
void APokemon::SetPokemon(std::string_view _PokemonName)
{
	SetName(_PokemonName);
	if (SpriteRenderer == nullptr) {
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	}

	if (AbilityController == nullptr) {
		AbilityController = CreateDefaultSubObject<UAbilityController>();
	}
	//	스프라이트 세팅
	SpriteRenderer->SetSprite(GetName() + "_Idle.png");
	SpriteRenderer->SetSpriteScale();
	//	애니메이션 세팅
	SetAnim();
	//	랜더오더
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	//	기본
	Dir = DIR::Down;
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


void APokemon::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration / 0.5f);
	SetActorLocation(NewLocation);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}












