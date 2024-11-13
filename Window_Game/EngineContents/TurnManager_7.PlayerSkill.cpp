#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"


void ATurnManager::PlayerSkill(float _DeltaTime)
{
	Player->Skill();
	if (false == Player->IsAttack()) {
		Player->SetTargetPokemon(nullptr);
		CurTurnType = TurnType::Skill_AI_Select;
	}


}