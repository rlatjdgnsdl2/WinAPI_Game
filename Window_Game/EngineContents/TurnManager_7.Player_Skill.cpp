#include "PreCompile.h"
#include "TurnManager.h"
#include "Partner.h"
#include "Player.h"


void ATurnManager::PlayerSkill(float _DeltaTime)
{
	
	Player->Skill();

	//	플레이어의 공격이 끝났는지 아는법
	//	후보 1. 애니메이션?
	//	후보 2. 충돌체크
	CurTurnType = TurnType::Skill_AI_Select;
}