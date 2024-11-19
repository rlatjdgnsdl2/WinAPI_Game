#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"
#include "SkillController.h"
#include "AbilityController.h"

#include "TextManager.h"


void ATurnManager::PlayerSkill()
{
	USkillController* PlayerSkill = Player->GetSkillController();
	APokemon* TargetPokemon = PlayerSkill->GetTargetPokemon();
	Player->Skill(SkillType::NormalAttack);
	if (TargetPokemon != nullptr) {

		if ('A' == PlayerInput) {
			if (true == Player->IsAttack()) {
				return;
			}
		}
		if ('S' == PlayerInput) {
			Player->Skill(SkillType::SpecialAttack);
			if (true == Player->IsAttack()) {
				return;
			}
		}
		// 공격이 끝났으면 타겟포켓몬이 죽었는지 확인
		if (TargetPokemon != nullptr) {
			//	타겟포켓몬이 죽었으면
			if (true == TargetPokemon->GetCurAbility()->IsDie()) {
				CampType TargetCamp = TargetPokemon->GetCamp();
				std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? PlayerCamp : EnemyCamp;
				//	모든 리스트에서 제거
				AllAIPokemon.remove(TargetPokemon);
				CompareCamp.remove(TargetPokemon);
				SkillPokemon.remove(TargetPokemon);
				MovePokemon.remove(TargetPokemon);
				TargetPokemon->Destroy();
				//CurTurn = TurnType::Result;
			}
		}
		PlayerSkill->SetTargetPokemon(nullptr);
	}
	CurTurn = TurnType::Skill_AI_Select;
	return;
}