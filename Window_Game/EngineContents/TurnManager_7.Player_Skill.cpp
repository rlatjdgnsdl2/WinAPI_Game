#include "PreCompile.h"
#include "TurnManager.h"
#include "Partner.h"
#include "Player.h"


void ATurnManager::PlayerSkill(float _DeltaTime)
{
	
	Player->Skill();

	//	�÷��̾��� ������ �������� �ƴ¹�
	//	�ĺ� 1. �ִϸ��̼�?
	//	�ĺ� 2. �浹üũ
	CurTurnType = TurnType::Skill_AI_Select;
}