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
	// 공격이 끝났으면 타겟포켓몬이 죽었는지 확인
	if (TargetPokemon != nullptr) {
		//	타겟포켓몬이 죽었으면
		if (true == TargetPokemon->IsDie()) {
			int Level = TargetPokemon->GetLevel();
			DungeonUI->NewLogMessage(
				{ TargetPokemon->GetName()," Die and ",Player->GetName(),  " Gain EXP ",std::to_string(TargetPokemon->GetLevel() * 100) }, { TextColor::Blue,TextColor::White,TextColor::Blue,TextColor::White,TextColor::Yellow });
			// 경험치 획득 후 레벨업했으면
			if (true == Player->GainExp(TargetPokemon->GetLevel() * 100)) {
				DungeonUI->NewLogMessage(
					{ Player->GetName()," Level Up!", }, {TextColor::Blue,TextColor::Yellow});
			}
			CampType TargetCamp = TargetPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CampType::Player == TargetCamp) ? PlayerCamp : EnemyCamp;
			//	모든 리스트에서 제거
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


