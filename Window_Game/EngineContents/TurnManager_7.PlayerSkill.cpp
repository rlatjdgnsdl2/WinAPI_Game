#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"
#include "SkillController.h"
#include "AbilityController.h"


void ATurnManager::PlayerSkill()
{
	USkillController* PlayerSkill = Player->GetSkillController();
	if ('A' == PlayerInput) {
		Player->Skill(SkillType::NormalAttack);
		if (true == Player->IsAttack()) {
			return;
		}
	}

	// 공격이 끝났으면 타겟포켓몬이 죽었는지 확인
	APokemon* TargetPokemon = PlayerSkill->GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		//	타겟포켓몬이 죽었으면
		if (true == TargetPokemon->GetCurAbility()->IsDie()) {
			CampType TargetCamp = TargetPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? EnemyCamp : PlayerCamp;
			//	모든 리스트에서 제거
			AllAIPokemon.remove(TargetPokemon);
			CompareCamp.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	PlayerSkill->SetTargetPokemon(nullptr);
	CurTurn = TurnType::Skill_AI_Select;
	return;
}