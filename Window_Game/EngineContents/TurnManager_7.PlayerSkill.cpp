#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"

#include "DungeonUI.h"




void ATurnManager::PlayerSkillStart() {
	Player->StartAttack();
	APokemon* TargetPokemon = Player->GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		int Damage = UContentsMath::DamageCalculation(Player->GetATK(), TargetPokemon->GetDEF());
		DungeonUI->NewLogMessage(
			{Player->GetName()," damage to ", TargetPokemon->GetName()," for " ,std::to_string(Damage) }, {TextColor::Blue,TextColor::White,TextColor::Blue,TextColor::White,TextColor::Yellow});
		TargetPokemon->SetDamage(Damage);
	}

	CurTurn = TurnType::Player_Skill;
}


void ATurnManager::PlayerSkill()
{
	Player->Skill();
	if (true == Player->IsAttack()) {
		return;
	}
	CurTurn = TurnType::Player_Skill_End;
}

void ATurnManager::PlayerSkillEnd()
{
	APokemon* TargetPokemon = Player->GetTargetPokemon();
	// ������ �������� Ÿ�����ϸ��� �׾����� Ȯ��
	if (TargetPokemon != nullptr) {
		//	Ÿ�����ϸ��� �׾�����
		if (true == TargetPokemon->IsDie()) {
			int Level = TargetPokemon->GetLevel();
			DungeonUI->NewLogMessage(
				{ TargetPokemon->GetName()," Die and ",Player->GetName(),  " Gain EXP ",std::to_string(TargetPokemon->GetLevel() * 100) }, { TextColor::Blue,TextColor::White,TextColor::Blue,TextColor::White,TextColor::Yellow });
			// ����ġ ȹ�� �� ������������
			if (true == Player->GainExp(TargetPokemon->GetLevel() * 100)) {
				DungeonUI->NewLogMessage(
					{ Player->GetName()," Level Up!", }, {TextColor::Blue,TextColor::Yellow});
			}
			CampType TargetCamp = TargetPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? PlayerCamp : EnemyCamp;
			//	��� ����Ʈ���� ����
			AllAIPokemon.remove(TargetPokemon);
			CompareCamp.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	Player->SetTargetPokemon(nullptr);
	CurTurn = TurnType::Skill_AI_Select;
	return;
}


