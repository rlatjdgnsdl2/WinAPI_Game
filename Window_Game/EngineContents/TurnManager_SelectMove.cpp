#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"

//	Select_Move단계
void ATurnManager::SelectMove(int _PlayerInput)
{
	// Player 이동방향 결정
	int PlayerInput = _PlayerInput;
	switch (_PlayerInput)
	{
	case VK_NUMPAD8:
		InitPlayerMove(DIR::Up, FVector2D::UP * 72);
		break;
	case VK_NUMPAD7:
		InitPlayerMove(DIR::Left_Up, FVector2D::UP * 72 + FVector2D::LEFT * 72);
		break;
	case VK_NUMPAD4:
		InitPlayerMove(DIR::Left, FVector2D::LEFT * 72);
		break;
	case VK_NUMPAD1:
		InitPlayerMove(DIR::Left_Down, FVector2D::DOWN * 72 + FVector2D::LEFT * 72);
		break;
	case VK_NUMPAD2:
		InitPlayerMove(DIR::Down, FVector2D::DOWN * 72);
		break;
	case VK_NUMPAD3:
		InitPlayerMove(DIR::Right_Down, FVector2D::DOWN * 72 + FVector2D::RIGHT * 72);
		break;
	case VK_NUMPAD6:
		InitPlayerMove(DIR::Right, FVector2D::RIGHT * 72);
		break;
	case VK_NUMPAD9:
		InitPlayerMove(DIR::Right_Up, FVector2D::UP * 72 + FVector2D::RIGHT * 72);
		break;
	default:
		break;
	}
	//	다음단계
	CurTurnType = TurnType::Move_AI_Select;
};

void ATurnManager::InitPlayerMove(DIR direction, FVector2D moveVector)
{
	Player->SetDir(direction);
	FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
	FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + moveVector);
	TileType TargetTileType = Dungeon->GetTileType(TargetLocation.iX() / 72, TargetLocation.iY() / 72);
	Player->SetCurDuration(0.0f);
	//if (TileType::GROUND != TargetTileType) {
	//	Player->SetTargetLocation(StartLocation); // 이동 불가시 원래 위치로
	//	return;
	//}
}