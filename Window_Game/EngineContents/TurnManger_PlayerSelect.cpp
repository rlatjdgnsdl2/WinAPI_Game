#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Dungeon.h"
#include "Player.h"
#include "Pokemon.h"
#include "Partner.h"


void ATurnManager::PlayerSelect()
{
	Player->Idle();
	std::map<float, APokemon*>::iterator StartIter = IdleMaps.begin();
	std::map<float, APokemon*>::iterator EndIter = IdleMaps.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = StartIter->second;
		CurPokemon->Idle();
	}
	// 각 방향에 대해 이동을 처리
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerInput = VK_NUMPAD8;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerInput = VK_NUMPAD7;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerInput = VK_NUMPAD4;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerInput = VK_NUMPAD1;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerInput = VK_NUMPAD2;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerInput = VK_NUMPAD3;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerInput = VK_NUMPAD6;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerInput = VK_NUMPAD9;
		CurTurnType = TurnType::Player_Select_Move;
	}
	else if (UEngineInput::GetInst().IsPress('A')) {
		PlayerInput = 'A';
		CurTurnType = TurnType::Player_Select_Skill;
	}
}



