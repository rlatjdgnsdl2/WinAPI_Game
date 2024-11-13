#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Player.h"
#include "Pokemon.h"

//	Player_Select단계
void ATurnManager::PlayerSelect()
{
	Player->Idle();
	PlayerMoveDir = FVector2D::ZERO;
	// Player_Select_Move 단계로 가는 키
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		PlayerMoveDir += FVector2D::UP;
		Player->SetCurDir(DIR::Up);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		PlayerMoveDir += FVector2D::UP + FVector2D::LEFT;
		Player->SetCurDir(DIR::Left_Up);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		PlayerMoveDir += FVector2D::LEFT;
		Player->SetCurDir(DIR::Left);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		PlayerMoveDir += FVector2D::DOWN + FVector2D::LEFT;
		Player->SetCurDir(DIR::Left_Down);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		PlayerMoveDir += FVector2D::DOWN;
		Player->SetCurDir(DIR::Down);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		PlayerMoveDir += FVector2D::DOWN + FVector2D::RIGHT;
		Player->SetCurDir(DIR::Right_Down);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		PlayerMoveDir += FVector2D::RIGHT;
		Player->SetCurDir(DIR::Right);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		PlayerMoveDir += FVector2D::UP + FVector2D::RIGHT;
		Player->SetCurDir(DIR::Right_Up);
		CurTurnType = TurnType::Player_Select_Move;
		return;
	}
	// Player_Select_Skill 단계로 가는 키
	if (UEngineInput::GetInst().IsPress('A')) {
		Player->SetCurSkillType(SkillType::NormalAttack);
		PlayerInput = 'A';
		CurTurnType = TurnType::Player_Select_Skill;
		return;
	}

	
	// AI Idle
	std::list<class APokemon*> ::iterator StartIter = AllAIPokemon.begin();
	std::list<class APokemon*> ::iterator EndIter = AllAIPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Idle();
	}

}



