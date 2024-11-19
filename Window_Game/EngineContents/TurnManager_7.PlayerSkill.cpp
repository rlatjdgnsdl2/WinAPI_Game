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
		// ������ �������� Ÿ�����ϸ��� �׾����� Ȯ��
		if (TargetPokemon != nullptr) {
			//	Ÿ�����ϸ��� �׾�����
			if (true == TargetPokemon->GetCurAbility()->IsDie()) {
				CampType TargetCamp = TargetPokemon->GetCamp();
				std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? PlayerCamp : EnemyCamp;
				//	��� ����Ʈ���� ����
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