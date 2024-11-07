#include "PreCompile.h"
#include "TurnManager.h"
#include "Partner.h"
#include "Player.h"


void ATurnManager::PlayerSkill(float _DeltaTime)
{
	CurTurnType = TurnType::Skill_AI_Select;
}