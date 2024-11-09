#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"

//	Select_Move단계
void ATurnManager::SelectMove(int _PlayerInput)
{
	// Player 이동방향 결정
	int PlayerInput = _PlayerInput;
	bool IsMoveAble = false;
	switch (_PlayerInput)
	{
	case VK_NUMPAD8:
		IsMoveAble = InitPlayerMove(DIR::Up, FVector2D::UP * 72);
		break;
	case VK_NUMPAD7:
		IsMoveAble = InitPlayerMove(DIR::Left_Up, FVector2D::UP * 72 + FVector2D::LEFT * 72);
		break;
	case VK_NUMPAD4:
		IsMoveAble = InitPlayerMove(DIR::Left, FVector2D::LEFT * 72);
		break;
	case VK_NUMPAD1:
		IsMoveAble = InitPlayerMove(DIR::Left_Down, FVector2D::DOWN * 72 + FVector2D::LEFT * 72);
		break;
	case VK_NUMPAD2:
		IsMoveAble = InitPlayerMove(DIR::Down, FVector2D::DOWN * 72);
		break;
	case VK_NUMPAD3:
		IsMoveAble = InitPlayerMove(DIR::Right_Down, FVector2D::DOWN * 72 + FVector2D::RIGHT * 72);
		break;
	case VK_NUMPAD6:
		IsMoveAble = InitPlayerMove(DIR::Right, FVector2D::RIGHT * 72);
		break;
	case VK_NUMPAD9:
		IsMoveAble = InitPlayerMove(DIR::Right_Up, FVector2D::UP * 72 + FVector2D::RIGHT * 72);
		break;
	default:
		break;
	}
	if (IsMoveAble) {
		CurTurnType = TurnType::Move_AI_Select;
	}
	else if (!IsMoveAble) {
		CurTurnType = TurnType::Player_Select;
	}
	//	다음단계
};

bool ATurnManager::InitPlayerMove(DIR direction, FVector2D moveVector)
{
	Player->SetDir(direction);
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetStartLocation() + moveVector);
	FVector2D TargetLocation = Player->GetTargetLocation();
	TileType TargetTileType = Dungeon->GetTileType(TargetLocation.iX() / 72, TargetLocation.iY() / 72);
	Player->SetCurDuration(0.0f);
	//	이동불가능하면
	if (TileType::GROUND != TargetTileType) {
		Player->SetTargetLocation(Player->GetStartLocation()); 
		return false;
	}
	return true;
}