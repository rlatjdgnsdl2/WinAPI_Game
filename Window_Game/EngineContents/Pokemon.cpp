#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>

#include "GameDataManager.h"
#include "AbilityController.h"

#include "SpecialSkill.h"


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
	AnimSet();
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

void APokemon::NormalAttack()
{
	SpriteRenderer->ChangeAnimation("AttackAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::SpecialAttack()
{
	if (SpecialSkill == nullptr) {
		SpecialSkill = GetWorld()->SpawnActor<ASpecialSkill>("Lightning_Bomb");
		SpecialSkill->SetActorLocation(GetActorLocation() + UContentsMath::DIR_To_Vector2D(Dir) * 72.0f);
		return;
	}
	if (false == SpecialSkill->IsAttack()) {

		EndAttack();
		SpecialSkill->Destroy();
		SpecialSkill = nullptr;
	};
}

void APokemon::ReadyAttack()
{
	IsAttackValue = true;
	SpriteRenderer->SetOrder(ERenderOrder::ATTACK_Player);
}

void APokemon::EndAttack()
{
	APokemon* TargetPokemon = GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		TargetPokemon->GetCurAbility()->SetDamage(AbilityController->GetATK());
	}
	IsAttackValue = false;
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
}

void APokemon::PlayHurtAnim()
{
	APokemon* TargetPokemon = GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		DIR TargetDir = UContentsMath::ReverseDir(Dir);
		TargetPokemon->SetDir(TargetDir);
		TargetPokemon->Hurt();
	}
}

bool APokemon::IsAttack() {
	return IsAttackValue;
};

void APokemon::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration / 0.5f);
	SetActorLocation(NewLocation);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}












