#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Player.h"
#include "Pokemon.h"

//	Player_Select단계
void ATurnManager::PlayerSelect()
{
	Player->Idle();
	MoveDir = FVector2D::ZERO;
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		MoveDir += FVector2D::UP;
		PlayerDir = DIR::Up;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		MoveDir += FVector2D::UP + FVector2D::LEFT;
		PlayerDir = DIR::Left_Up;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		MoveDir += FVector2D::LEFT;
		PlayerDir = DIR::Left;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		MoveDir += FVector2D::DOWN + FVector2D::LEFT;
		PlayerDir = DIR::Left_Down;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		MoveDir += FVector2D::DOWN;
		PlayerDir = DIR::Down;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		MoveDir += FVector2D::DOWN + FVector2D::RIGHT;
		PlayerDir = DIR::Right_Down;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		MoveDir += FVector2D::RIGHT;
		PlayerDir = DIR::Right;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		MoveDir += FVector2D::UP + FVector2D::RIGHT;
		PlayerDir = DIR::Right_Up;
	}
	// Player_Select_Skill 단계로 가는 키
	/*else if (UEngineInput::GetInst().IsPress('A')) {
		PlayerInput = 'A';
		CurTurnType = TurnType::Player_Select_Skill;
	}*/

	else if (UEngineInput::GetInst().IsPress('U')) {
		PlayerInput = 'U';
		SwithcDebugMode();
		if (IsDebugMode == true) {
			GetWorld()->SetCameraToMainPawn(false);
		}
		else {
			GetWorld()->SetCameraToMainPawn(true);
		}
	}

	if (MoveDir != FVector2D::ZERO) {
		CurTurnType = TurnType::Player_Select_Move;
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



