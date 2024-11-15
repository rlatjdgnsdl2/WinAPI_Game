#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>


void APokemon::Skill()
{
	switch (Skill)
	{
	case SkillType::NormalAttack:
		SpriteRenderer->ChangeAnimation("AttackAnim_" + std::to_string(static_cast<int>(Dir)));
		SpriteRenderer->SetSpriteScale();
		break;
	case SkillType::SpecialAttack:
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

void APokemon::StartAttack()
{
	IsAttackValue = true;
	SpriteRenderer->SetOrder(ERenderOrder::ATTACK_Player);

}

void APokemon::EndAttack()
{
	IsAttackValue = false;
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
}

void APokemon::PlayHurtAnim()
{
	if (TargetPokemon != nullptr) {
		DIR TargetDir = UContentsMath::ReverseDir(Dir);
		TargetPokemon->SetDir(TargetDir);
		TargetPokemon->Hurt();
	}
}


const SkillType& APokemon::GetSkillType() const {
	return Skill;
}
void APokemon::SetSkillType(SkillType _SkillType) {
	Skill = _SkillType;
}


class APokemon* APokemon::GetTargetPokemon() const {
	return TargetPokemon;
}
void APokemon::SetTargetPokemon(class APokemon* _TargetPokemon) {
	TargetPokemon = _TargetPokemon;
}

bool APokemon::IsAttack() {
	return IsAttackValue;
};