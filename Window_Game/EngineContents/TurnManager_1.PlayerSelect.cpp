#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Player.h"
#include "Pokemon.h"

//	Player_Select단계
void ATurnManager::PlayerSelect()
{
	Player->Idle();

	//	타일맵실험
	if (IsDebugMode == true) {
		if (true == UEngineInput::GetInst().IsPress('I'))
		{
			FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::UP * 72;
			GetWorld()->SetCameraPos(NewCameraPos);
		}
		if (true == UEngineInput::GetInst().IsPress('J'))
		{
			FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::LEFT * 72;
			GetWorld()->SetCameraPos(NewCameraPos);
		}
		if (true == UEngineInput::GetInst().IsPress('K'))
		{
			FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::DOWN * 72;
			GetWorld()->SetCameraPos(NewCameraPos);
		}
		if (true == UEngineInput::GetInst().IsPress('L'))
		{
			FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::RIGHT * 72;
			GetWorld()->SetCameraPos(NewCameraPos);
		}
	}


	PlayerMoveVec = FVector2D::ZERO;
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerMoveVec += FVector2D::UP;
		PlayerDir = DIR::Up;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerMoveVec += FVector2D::UP + FVector2D::LEFT;
		PlayerDir = DIR::Left_Up;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerMoveVec += FVector2D::LEFT;
		PlayerDir = DIR::Left;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerMoveVec += FVector2D::DOWN + FVector2D::LEFT;
		PlayerDir = DIR::Left_Down;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerMoveVec += FVector2D::DOWN;
		PlayerDir = DIR::Down;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerMoveVec += FVector2D::DOWN + FVector2D::RIGHT;
		PlayerDir = DIR::Right_Down;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerMoveVec += FVector2D::RIGHT;
		PlayerDir = DIR::Right;
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerMoveVec += FVector2D::UP + FVector2D::RIGHT;
		PlayerDir = DIR::Right_Up;
	}
	// Player_Select_Skill 단계로 가는 키
	else if (UEngineInput::GetInst().IsPress('A')) {
		PlayerInput = 'A';
		CurTurnType = TurnType::Player_Select_Skill;
	}

	else if (UEngineInput::GetInst().IsDown('U')) {
		PlayerInput = 'U';
		SwithcDebugMode();
		if (IsDebugMode == true) {
			GetWorld()->SetCameraToMainPawn(false);
		}
		else {
			GetWorld()->SetCameraToMainPawn(true);
		}
	}

	if (PlayerMoveVec != FVector2D::ZERO) {
		CurTurnType = TurnType::Player_Select_Move;
	}
	// AI Idle
	else
	{
		std::vector<class APokemon*> ::iterator StartIter = AllPokemon.begin();
		std::vector<class APokemon*> ::iterator EndIter = AllPokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			CurPokemon->Idle();
		}

	}
}



