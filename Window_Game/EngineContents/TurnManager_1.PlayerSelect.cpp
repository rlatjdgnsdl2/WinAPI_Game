#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Player.h"
#include "DungeonUI.h"


//	Player_Select�ܰ�
void ATurnManager::PlayerSelect(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	if (CurDuration > 5.0f)
	{
		if (DungeonUI->IsNewLog()) {
			DungeonUI->SetNewLogVal(false);
		}
	}
	Player->Idle();

	for (APokemon* CurPokemon : AllAIPokemon)
	{
		CurPokemon->Idle();
	}
	PlayerMoveDir = FVector2D::ZERO;

	if (UEngineInput::GetInst().IsDown('Q')) {
		PreTurn = CurTurn;
		DungeonUI->SetNewLogVal(false);
		CurTurn = TurnType::Open_UI;
		return;
	}
	// Player_Select_Move �ܰ�� ���� Ű
	if (UEngineInput::GetInst().IsPress(VK_SPACE))
	{
		if (UEngineInput::GetInst().IsPress(VK_LEFT) && UEngineInput::GetInst().IsPress(VK_UP))
		{
			PlayerMoveDir += FVector2D::UP + FVector2D::LEFT;
			Player->SetDir(DIR::Left_Up);
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_LEFT) && UEngineInput::GetInst().IsPress(VK_DOWN)) {
			PlayerMoveDir += FVector2D::DOWN + FVector2D::LEFT;
			Player->SetDir(DIR::Left_Down);
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_RIGHT) && UEngineInput::GetInst().IsPress(VK_DOWN)) {
			PlayerMoveDir += FVector2D::DOWN + FVector2D::RIGHT;
			Player->SetDir(DIR::Right_Down);
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		if (UEngineInput::GetInst().IsPress(VK_RIGHT) && UEngineInput::GetInst().IsPress(VK_UP)) {
			PlayerMoveDir += FVector2D::UP + FVector2D::RIGHT;
			Player->SetDir(DIR::Right_Up);
			CurTurn = TurnType::Player_Select_Move;
			return;
		}
		return;
	}

	//	ȸ��
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



	if (UEngineInput::GetInst().IsPress(VK_UP)) {
		PlayerMoveDir += FVector2D::UP;
		Player->SetDir(DIR::Up);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_LEFT)) {
		PlayerMoveDir += FVector2D::LEFT;
		Player->SetDir(DIR::Left);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_DOWN)) {
		PlayerMoveDir += FVector2D::DOWN;
		Player->SetDir(DIR::Down);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}

	if (UEngineInput::GetInst().IsPress(VK_RIGHT)) {
		PlayerMoveDir += FVector2D::RIGHT;
		Player->SetDir(DIR::Right);
		CurTurn = TurnType::Player_Select_Move;
		return;
	}



	// Player_Select_Skill �ܰ�� ���� Ű
	if (UEngineInput::GetInst().IsDown('A')) {
		PlayerInput = 'A';
		CurTurn = TurnType::Player_Select_Skill;
		return;
	}
	// Player_Select_Skill �ܰ�� ���� Ű
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



