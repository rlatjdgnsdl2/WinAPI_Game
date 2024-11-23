#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>


#include "SpecialSkill.h"




void APokemon::StartAttack() {
	IsAttackVal = true;
	SpriteRenderer->SetOrder(ERenderOrder::AttacK_Player);
}
void APokemon::EndAttack() {
	IsAttackVal = false;
	SpriteRenderer->SetOrder(ERenderOrder::Player);
}

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
		SpecialSkill = GetWorld()->SpawnActor<ASpecialSkill>(CurSpecialSkillName);
		SpecialSkill->SetActorLocation(GetActorLocation() + UContentsMath::DIR_To_FVector2D(Dir) * 72.0f);
		return;
	}
	if (false == SpecialSkill->IsAttack()) {
		EndAttack();
		SpecialSkill->Destroy();
		SpecialSkill = nullptr;
	};
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