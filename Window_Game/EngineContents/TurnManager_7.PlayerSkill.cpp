#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"

#include "AbilityController.h"



void ATurnManager::PlayerSkill()
{
	APokemon* TargetPokemon = Player->GetTargetPokemon();
	Player->Skill();
	if (true == Player->IsAttack()) {
		return;
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
	Player->SetTargetPokemon(nullptr);
	CurTurn = TurnType::Skill_AI_Select;
	return;
}