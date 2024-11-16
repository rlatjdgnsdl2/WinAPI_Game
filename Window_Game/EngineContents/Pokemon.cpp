#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>
#include "MoveController.h"
#include "SkillController.h"
#include "AbilityController.h"
#include "GameDataManager.h"



APokemon::APokemon()
{
}

APokemon::~APokemon()
{

}

void APokemon::SetPokemon(std::string_view _PokemonName)
{
	if (SpriteRenderer == nullptr) {
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	}
	if (MoveController == nullptr) {
		MoveController = CreateDefaultSubObject<UMoveController>();
	}
	if (SkillController == nullptr) {
		SkillController = CreateDefaultSubObject<USkillController>();
	}
	SetName(_PokemonName);
	//	��������Ʈ ����
	SpriteRenderer->SetSprite(GetName() + "_Idle.png");
	SpriteRenderer->SetSpriteScale();
	//	�ִϸ��̼� ����
	AnimSet();
	//	��������
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	//	�⺻
	Dir = DIR::Down;
	SkillType CurSkillType = SkillType::NormalAttack;
}

void APokemon::Idle()
{
	SpriteRenderer->ChangeAnimation("IdleAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Skill(SkillType _Skill)
{
	switch (_Skill)
	{
	case SkillType::NormalAttack:
		NormalAttack();
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

void APokemon::NormalAttack()
{
	SpriteRenderer->ChangeAnimation("AttackAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::StartAttack()
{
	IsAttackValue = true;
	SpriteRenderer->SetOrder(ERenderOrder::ATTACK_Player);
}

void APokemon::EndAttack()
{
	APokemon* TargetPokemon = SkillController->GetTargetPokemon();
	if (SkillController->GetTargetPokemon() != nullptr) {
		TargetPokemon->GetCurAbility()->SetDamage(AbilityController->GetATK());
	}
	IsAttackValue = false;
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
}

void APokemon::PlayHurtAnim()
{
	APokemon* TargetPokemon = SkillController->GetTargetPokemon();
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
	MoveController->Move(_DeltaTime);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}












