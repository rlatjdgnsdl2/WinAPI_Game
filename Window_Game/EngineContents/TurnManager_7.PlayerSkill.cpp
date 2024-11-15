#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"


void ATurnManager::PlayerSkill()
{

	Player->Skill();
	if (true==Player->IsAttack()) {
		return;
	}
	CurTurnType = TurnType::Skill_AI_Select;
	return;
}