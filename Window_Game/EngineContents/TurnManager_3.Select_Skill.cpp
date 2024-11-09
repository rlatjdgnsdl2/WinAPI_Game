#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill(int _PlayerInput)
{
	switch (_PlayerInput)
	{
	case'A':
		Player->SetCurSkillType(SkillType::NormalAttack);
		break;
	case'S':
		Player->SetCurSkillType(SkillType::SpecialAttack);
		break;
	default:
		Player->SetCurSkillType(SkillType::UseItem);
		break;
	}
	CurTurnType = TurnType::Player_Skill;
}