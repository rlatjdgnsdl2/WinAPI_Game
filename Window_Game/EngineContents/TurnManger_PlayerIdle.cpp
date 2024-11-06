#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Dungeon.h"
#include "Player.h"
#include "Partner.h"


void ATurnManager::PlayerIdle()
{
	CurDuration = 0.0f;
	Player->Idle();
	Partner->Idle();

	// �� ���⿡ ���� �̵��� ó��
	if (UEngineInput::GetInst().IsPress(VK_NUMPAD8)) {
		InitPlayerMove(DIR::Up, FVector2D::UP * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD7)) {
		InitPlayerMove(DIR::Left_Up, FVector2D::UP * 72 + FVector2D::LEFT * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD4)) {
		InitPlayerMove(DIR::Left, FVector2D::LEFT * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD1)) {
		InitPlayerMove(DIR::Left_Down, FVector2D::DOWN * 72 + FVector2D::LEFT * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD2)) {
		InitPlayerMove(DIR::Down, FVector2D::DOWN * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD3)) {
		InitPlayerMove(DIR::Right_Down, FVector2D::DOWN * 72 + FVector2D::RIGHT * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD6)) {
		InitPlayerMove(DIR::Right, FVector2D::RIGHT * 72);
	}
	else if (UEngineInput::GetInst().IsPress(VK_NUMPAD9)) {
		InitPlayerMove(DIR::Right_Up, FVector2D::UP * 72 + FVector2D::RIGHT * 72);
	}
	else if (UEngineInput::GetInst().IsPress('A')) {
		CurTurnType = TurnType::PlayerAttack;
	}
	// ��Ʈ���� ��ǥ ��ġ ���� �� ���� ����
	SetPartnerDir();
}



