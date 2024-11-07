#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Dungeon.h"
#include "Player.h"
#include "Pokemon.h"
#include "Partner.h"

//	Player_Select단계
void ATurnManager::PlayerSelect()
{
	//	플레이어는 입력을 대기받는다
	Player->Idle();
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerInput = VK_NUMPAD8;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerInput = VK_NUMPAD7;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerInput = VK_NUMPAD4;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerInput = VK_NUMPAD1;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerInput = VK_NUMPAD2;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerInput = VK_NUMPAD3;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerInput = VK_NUMPAD6;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerInput = VK_NUMPAD9;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}

	// Player_Select_Skill 단계로 가는 키
	else if (UEngineInput::GetInst().IsPress('A')) {
		PlayerInput = 'A';
		CurTurnType = TurnType::Player_Select_Skill;
		return;
	}
	// AI Idle
	else
	{
		std::vector<class APokemon*> ::iterator StartIter = IdleVec.begin();
		std::vector<class APokemon*> ::iterator EndIter = IdleVec.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			CurPokemon->Idle();
		}

	}
}



