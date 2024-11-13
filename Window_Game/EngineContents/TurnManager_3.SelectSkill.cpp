#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	SkillType CurPlayerSKillType = Player->GetCurSkillType();
	switch (CurPlayerSKillType)
	{
	case SkillType::NormalAttack:
		break;
	case SkillType::SpecialAttack:
		break;
	case SkillType::UseItem:
		break;
	default:
		break;
	}

	CurTurnType = TurnType::Player_Skill;
}