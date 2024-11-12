#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"

//	Select_Move단계
void ATurnManager::SelectMove(int _PlayerInput)
{
	// Player 이동방향 결정
	int PlayerInput = _PlayerInput;
	bool IsMoveable = false;
	IsMoveable = InitPlayerMove(PlayerDir, PlayerMoveVec);

	if (IsMoveable) {
		CurTurnType = TurnType::Move_AI_Select;
		return;
	}
	if (!IsMoveable) {
		CurTurnType = TurnType::Player_Select;
		return;
	}

};

bool ATurnManager::InitPlayerMove(DIR direction, FVector2D moveVector)
{
	Player->SetCurDir(direction);
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetStartLocation() + moveVector * 72);
	FVector2D TargetLocation = Player->GetTargetLocation();
	TileType TargetTileType = Dungeon->GetTileType(TargetLocation.iX() / 72, TargetLocation.iY() / 72);
	if (TileType::GROUND == TargetTileType) {
		Player->SetCurDuration(0.0f);
		return true;
	}
	Player->SetTargetLocation(Player->GetStartLocation()); // 이동 불가시 원래 위치로
	return false;
}


