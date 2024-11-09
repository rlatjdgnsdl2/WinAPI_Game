#include "PreCompile.h"
#include "TurnManager.h"

void ATurnManager::Skill_AISelect(float _DeltaTime)
{
	CurTurnType = TurnType::AI_Move;
}