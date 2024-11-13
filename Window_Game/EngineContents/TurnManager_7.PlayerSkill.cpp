#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"


void ATurnManager::PlayerSkill(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	Player->Skill();



	if (false == Player->IsAttack()) {
		CurTurnType = TurnType::Skill_AI_Select;
	}


}