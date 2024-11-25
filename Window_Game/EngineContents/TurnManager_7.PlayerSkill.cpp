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
	// 공격이 끝났으면 타겟포켓몬이 죽었는지 확인
	if (TargetPokemon != nullptr) {
		//	타겟포켓몬이 죽었으면
		if (true == TargetPokemon->IsDie()) {
			int Level = TargetPokemon->GetLevel();
			UIManager->NewLogMessage(
				{ TargetPokemon->GetName()," Die and ","Player Party"," Gain EXP ",std::to_string(Level * 100)}, 
				{Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow});
			// 경험치 획득 후 레벨업했으면
			for (APokemon* CurPokemon : PlayerCamp) {
				if (CurPokemon != nullptr && CurPokemon->GainExp(Level * 100)) {
					UIManager->NewLogMessage(
						{ CurPokemon->GetName()," Level Up!", }, { Color::Blue,Color::Yellow });
					UIManager->NewLogMessage(
						{ "All Ability ","+2" }, { Color::White,Color::Yellow });
				}
			}
			//	모든 리스트에서 제거
			CampType TargetCamp = TargetPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? PlayerCamp : EnemyCamp;
			AllAIPokemon.remove(TargetPokemon);
			CompareCamp.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	// 타겟초기화
	Player->SetTargetPokemon(nullptr);
	CurTurn = TurnType::Skill_AI_Select;
	return;
}


