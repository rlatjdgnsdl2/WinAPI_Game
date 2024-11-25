#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"
#include "UIManager.h"





void ATurnManager::PlayerSkillStart() {
	Player->StartAttack();
	APokemon* TargetPokemon = Player->GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		int Damage = UContentsMath::DamageCalculation(Player->GetATK(), TargetPokemon->GetDEF());
		UIManager->NewLogMessage(
			{Player->GetName()," damage to ", TargetPokemon->GetName()," for " ,std::to_string(Damage) }, {Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow});
		TargetPokemon->SetDamage(Damage);
	}
	CurTurn = TurnType::Player_Skill;
	return;
}


void ATurnManager::PlayerSkill()
{
	Player->Skill();
	if (true == Player->IsAttack()) {
		return;
	}
	CurTurn = TurnType::Player_Skill_End;
	return;
}

void ATurnManager::PlayerSkillEnd()
{
	APokemon* TargetPokemon = Player->GetTargetPokemon();
	// ������ �������� Ÿ�����ϸ��� �׾����� Ȯ��
	if (TargetPokemon != nullptr) {
		//	Ÿ�����ϸ��� �׾�����
		if (true == TargetPokemon->IsDie()) {
			int Level = TargetPokemon->GetLevel();
			UIManager->NewLogMessage(
				{ TargetPokemon->GetName()," Die and ","Player Party"," Gain EXP ",std::to_string(Level * 100)}, 
				{Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow});
			// ����ġ ȹ�� �� ������������
			for (APokemon* CurPokemon : PlayerCamp) {
				if (CurPokemon != nullptr && CurPokemon->GainExp(Level * 100)) {
					UIManager->NewLogMessage(
						{ CurPokemon->GetName()," Level Up!", }, { Color::Blue,Color::Yellow });
					UIManager->NewLogMessage(
						{ "All Ability ","+2" }, { Color::White,Color::Yellow });
				}
			}
			//	��� ����Ʈ���� ����
			CampType TargetCamp = TargetPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? PlayerCamp : EnemyCamp;
			AllAIPokemon.remove(TargetPokemon);
			CompareCamp.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	// Ÿ���ʱ�ȭ
	Player->SetTargetPokemon(nullptr);
	CurTurn = TurnType::Skill_AI_Select;
	return;
}


