#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Player.h"
#include "Pokemon.h"
#include "Box.h"


//	Player_Select단계
void ATurnManager::PlayerSelect()
{
	Player->Idle();

	for (APokemon* CurPokemon : AllAIPokemon)
	{
		CurPokemon->Idle();
	}
	PlayerMoveDir = FVector2D::ZERO;

	if (UEngineInput::GetInst().IsPress('Q')) {
		CurTurn = TurnType::Open_Menu;
		return;
	}
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerMoveDir += FVector2D::UP;
		Player->SetDir(DIR::Up);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerMoveDir += FVector2D::UP + FVector2D::LEFT;
		Player->SetDir(DIR::Left_Up);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerMoveDir += FVector2D::LEFT;
		Player->SetDir(DIR::Left);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerMoveDir += FVector2D::DOWN + FVector2D::LEFT;
		Player->SetDir(DIR::Left_Down);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerMoveDir += FVector2D::DOWN;
		Player->SetDir(DIR::Down);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerMoveDir += FVector2D::DOWN + FVector2D::RIGHT;
		Player->SetDir(DIR::Right_Down);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerMoveDir += FVector2D::RIGHT;
		Player->SetDir(DIR::Right);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerMoveDir += FVector2D::UP + FVector2D::RIGHT;
		Player->SetDir(DIR::Right_Up);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	
	// Player_Select_Skill 단계로 가는 키
	if (UEngineInput::GetInst().IsDown('A')) {
		PlayerInput = 'A';
		CurTurn = TurnType::Player_Select_Skill;
		return;
	}
	// Player_Select_Skill 단계로 가는 키
	if (UEngineInput::GetInst().IsDown('S')) {
 		PlayerInput = 'S';
		CurTurn = TurnType::Player_Select_Skill;
		return;
	}




}



