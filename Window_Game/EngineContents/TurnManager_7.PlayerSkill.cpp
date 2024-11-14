#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"


void ATurnManager::PlayerSkill()
{

	if (Player->IsAttack()) {
		Player->Skill();
		return;
	}
	Player->SetTargetPokemon(nullptr);
	CurTurnType = TurnType::Skill_AI_Select;
	return;
}