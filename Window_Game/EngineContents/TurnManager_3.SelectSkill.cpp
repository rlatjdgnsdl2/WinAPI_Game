#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	
	switch (PlayerInput)
	{
	case 'A':
		Player->SetCurSkillType(SkillType::NormalAttack);
		Player->StartAttack();
		break;
	default:
		break;
	}

	CurTurnType = TurnType::Player_Skill;
}