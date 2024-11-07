#include "PreCompile.h"
#include "TurnManager.h"

void ATurnManager::PlayerSkill_AISelect(float _DeltaTime)
{
	CurTurnType = TurnType::AI_Move;
}