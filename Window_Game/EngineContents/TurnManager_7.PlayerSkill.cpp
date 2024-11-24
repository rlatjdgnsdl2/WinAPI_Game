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
			{Player->GetName()," damage to ", TargetPokemon->GetName()," for " ,std::to_string(Damage) }, {Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow});
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
				{ TargetPokemon->GetName()," Die and ","Player Party",  " Gain EXP ",std::to_string(TargetPokemon->GetLevel() * 100)}, {Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow});
			// ����ġ ȹ�� �� ������������
			for (APokemon* CurPokemon : PlayerCamp) {
				if (CurPokemon != nullptr && CurPokemon->GainExp(TargetPokemon->GetLevel() * 100)) {
					DungeonUI->NewLogMessage(
						{ CurPokemon->GetName()," Level Up!", }, { Color::Blue,Color::Yellow });
					DungeonUI->NewLogMessage(
						{ "All Ability ","+2" }, { Color::White,Color::Yellow });
				}
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


