#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Dungeon.h"
#include "Player.h"
#include "Partner.h"


void ATurnManager::PlayerSelect()
{
	CurDuration = 0.0f;
	Player->Idle();
	Partner->Idle();

	// 각 방향에 대해 이동을 처리
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerInput = VK_NUMPAD8;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerInput = VK_NUMPAD7;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerInput = VK_NUMPAD4;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerInput = VK_NUMPAD1;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerInput = VK_NUMPAD2;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerInput = VK_NUMPAD3;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerInput = VK_NUMPAD6;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerInput = VK_NUMPAD9;
		CurTurnType = TurnType::Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress('A')) {
		PlayerInput = 'A';
		CurTurnType = TurnType::Select_Skill;
	}
}



