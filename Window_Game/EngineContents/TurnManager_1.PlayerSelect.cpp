#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Player.h"
#include "Pokemon.h"

//	Player_Select단계
void ATurnManager::PlayerSelect()
{
	Player->Idle();
	PlayerMoveVec = FVector2D::ZERO;
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerMoveVec += FVector2D::UP;
		PlayerDir = DIR::Up;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerMoveVec += FVector2D::UP + FVector2D::LEFT;
		PlayerDir = DIR::Left_Up;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerMoveVec += FVector2D::LEFT;
		PlayerDir = DIR::Left;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerMoveVec += FVector2D::DOWN + FVector2D::LEFT;
		PlayerDir = DIR::Left_Down;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerMoveVec += FVector2D::DOWN;
		PlayerDir = DIR::Down;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerMoveVec += FVector2D::DOWN + FVector2D::RIGHT;
		PlayerDir = DIR::Right_Down;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerMoveVec += FVector2D::RIGHT;
		PlayerDir = DIR::Right;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerMoveVec += FVector2D::UP + FVector2D::RIGHT;
		PlayerDir = DIR::Right_Up;
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	// Player_Select_Skill 단계로 가는 키
	if (UEngineInput::GetInst().IsPress('A')) {
		PlayerInput = 'A';
		CurTurnType = TurnType::Player_Select_Skill;
		return;
	}

	// 디버그모드
	if (UEngineInput::GetInst().IsDown('U')) {
		PlayerInput = 'U';
		GetWorld()->SetCameraToMainPawn(false);
		CurTurnType = TurnType::DebugMode;
		return;
	}
	// AI Idle
	std::vector<class APokemon*> ::iterator StartIter = AllPokemon.begin();
	std::vector<class APokemon*> ::iterator EndIter = AllPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Idle();
	}

}



