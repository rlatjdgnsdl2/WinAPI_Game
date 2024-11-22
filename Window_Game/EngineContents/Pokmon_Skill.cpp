#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>
#include "AbilityController.h"

#include "SpecialSkill.h"


void APokemon::SetSkill(SkillType _Skill) {
	CurSkill = _Skill;
};
SkillType APokemon::GetSkill() const {
	return CurSkill;
};

void APokemon::SetTargetPokemon(class APokemon* _TargetPokemon) {
	TargetPokemon = _TargetPokemon;
};
void APokemon::PushTargetablePokemon(class APokemon* _TargetablePokemon) {
	TargetablePokemons.push_back(_TargetablePokemon);
};
void APokemon::ClearTargetablePokemon() {
	TargetablePokemons.clear();
};

APokemon* APokemon::GetTargetPokemon() const {
	return TargetPokemon;
};
std::vector<class APokemon*>& APokemon::GetTargetablePokemons() {
	return TargetablePokemons;
};
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
void APokemon::NormalAttack()
{
	SpriteRenderer->ChangeAnimation("AttackAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::SpecialAttack()
{

	SpriteRenderer->ChangeAnimation("ShootAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();

	if (SpecialSkill == nullptr) {
		SpecialSkill = GetWorld()->SpawnActor<ASpecialSkill>(CurSpecialSKillName);
		SpecialSkill->SetActorLocation(GetActorLocation() + UContentsMath::DIR_To_Vector2D(Dir) * 72.0f);
		return;
	}
	if (false == SpecialSkill->IsAttack()) {

		EndAttack();
		SpecialSkill->Destroy();
		SpecialSkill = nullptr;
	};
}