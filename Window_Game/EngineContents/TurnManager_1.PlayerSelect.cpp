#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>
#include "Player.h"



//	Player_Select단계
void ATurnManager::PlayerSelect(float _DeltaTime)
{
	
	Player->Idle();
	for (APokemon* CurPokemon : AllAIPokemon)
	{
		CurPokemon->Idle();
	}
	PlayerMoveDir = FVector2D::ZERO;
	if (UEngineInput::GetInst().IsDown('Q')) {
		PreTurn = CurTurn;
		CurTurn = TurnType::Open_UI;
		return;
	}
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress('W')) {
		if (UEngineInput::GetInst().IsPress(VK_SPACE))
		{
			if (UEngineInput::GetInst().IsPress(VK_LEFT) && UEngineInput::GetInst().IsPress(VK_UP))
			{
				PlayerMoveDir += FVector2D::UP + FVector2D::LEFT;
				Player->SetDir(DIR::Left_Up);
				Player->SetRun();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			if (UEngineInput::GetInst().IsPress(VK_LEFT) && UEngineInput::GetInst().IsPress(VK_DOWN)) {
				PlayerMoveDir += FVector2D::DOWN + FVector2D::LEFT;
				Player->SetDir(DIR::Left_Down);
				Player->SetRun();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			if (UEngineInput::GetInst().IsPress(VK_RIGHT) && UEngineInput::GetInst().IsPress(VK_DOWN)) {
				PlayerMoveDir += FVector2D::DOWN + FVector2D::RIGHT;
				Player->SetDir(DIR::Right_Down);
				Player->SetRun();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			if (UEngineInput::GetInst().IsPress(VK_RIGHT) && UEngineInput::GetInst().IsPress(VK_UP)) {
				PlayerMoveDir += FVector2D::UP + FVector2D::RIGHT;
				Player->SetDir(DIR::Right_Up);
				Player->SetRun();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_UP)) {
			PlayerMoveDir += FVector2D::UP;
			Player->SetDir(DIR::Up);
			Player->SetRun();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_LEFT)) {
			PlayerMoveDir += FVector2D::LEFT;
			Player->SetDir(DIR::Left);
			Player->SetRun();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_DOWN)) {
			PlayerMoveDir += FVector2D::DOWN;
			Player->SetDir(DIR::Down);
			Player->SetRun();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}

		if (UEngineInput::GetInst().IsPress(VK_RIGHT)) {
			PlayerMoveDir += FVector2D::RIGHT;
			Player->SetDir(DIR::Right);
			Player->SetRun();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		return;
	}
	else {
		if (UEngineInput::GetInst().IsPress(VK_SPACE))
		{
			if (UEngineInput::GetInst().IsPress(VK_LEFT) && UEngineInput::GetInst().IsPress(VK_UP))
			{
				PlayerMoveDir += FVector2D::UP + FVector2D::LEFT;
				Player->SetDir(DIR::Left_Up);
				Player->SetWalk();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			if (UEngineInput::GetInst().IsPress(VK_LEFT) && UEngineInput::GetInst().IsPress(VK_DOWN)) {
				PlayerMoveDir += FVector2D::DOWN + FVector2D::LEFT;
				Player->SetDir(DIR::Left_Down);
				Player->SetWalk();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			if (UEngineInput::GetInst().IsPress(VK_RIGHT) && UEngineInput::GetInst().IsPress(VK_DOWN)) {
				PlayerMoveDir += FVector2D::DOWN + FVector2D::RIGHT;
				Player->SetDir(DIR::Right_Down);
				Player->SetWalk();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			if (UEngineInput::GetInst().IsPress(VK_RIGHT) && UEngineInput::GetInst().IsPress(VK_UP)) {
				PlayerMoveDir += FVector2D::UP + FVector2D::RIGHT;
				Player->SetDir(DIR::Right_Up);
				Player->SetWalk();
				CurTurn = TurnType::Player_Select_Move;
				return;
			}
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_UP)) {
			PlayerMoveDir += FVector2D::UP;
			Player->SetDir(DIR::Up);
			Player->SetWalk();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_LEFT)) {
			PlayerMoveDir += FVector2D::LEFT;
			Player->SetDir(DIR::Left);
			Player->SetWalk();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_DOWN)) {
			PlayerMoveDir += FVector2D::DOWN;
			Player->SetDir(DIR::Down);
			Player->SetWalk();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}

		if (UEngineInput::GetInst().IsPress(VK_RIGHT)) {
			PlayerMoveDir += FVector2D::RIGHT;
			Player->SetDir(DIR::Right);
			Player->SetWalk();
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
	}

	//	회전
	if (UEngineInput::GetInst().IsDown('R')) {
		DIR CurDir = Player->GetDir();
		switch (CurDir)
		{
		case DIR::Up:
			Player->SetDir(DIR::Right_Up);
			break;
		case DIR::Right_Up:
			Player->SetDir(DIR::Right);
			break;
		case DIR::Right:
			Player->SetDir(DIR::Right_Down);
			break;
		case DIR::Right_Down:
			Player->SetDir(DIR::Down);
			break;
		case DIR::Down:
			Player->SetDir(DIR::Left_Down);
			break;
		case DIR::Left_Down:
			Player->SetDir(DIR::Left);
			break;
		case DIR::Left:
			Player->SetDir(DIR::Left_Up);
			break;
		case DIR::Left_Up:
			Player->SetDir(DIR::Up);
			break;
		}
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



	// cheat
	if (UEngineInput::GetInst().IsDown('C'))
	{
		Player->LevelUp();
	}




}



