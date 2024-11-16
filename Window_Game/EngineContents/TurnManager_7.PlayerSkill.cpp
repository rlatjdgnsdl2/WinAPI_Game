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

	// ������ �������� Ÿ�����ϸ��� �׾����� Ȯ��
	APokemon* TargetPokemon = PlayerSkill->GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		//	Ÿ�����ϸ��� �׾�����
		if (true == TargetPokemon->GetCurAbility()->IsDie()) {
			CampType TargetCamp = TargetPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? EnemyCamp : PlayerCamp;
			//	��� ����Ʈ���� ����
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