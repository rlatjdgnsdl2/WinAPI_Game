#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"


void ATurnManager::PlayerSkill()
{

	Player->Skill();
	if (true == Player->IsAttack()) {
		return;
	}

	APokemon* TargetPokemon = Player->GetTargetPokemon();
	if (TargetPokemon != nullptr) {

		if (true == TargetPokemon->GetCurAbility().IsDie()) {
			AllAIPokemon.remove(TargetPokemon);
			EnemyCamp.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	Player->SetTargetPokemon(nullptr);
	CurTurnType = TurnType::Skill_AI_Select;
	return;
}