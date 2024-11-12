#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"

//	Select_Move단계
void ATurnManager::SelectMove()
{
	// Player 이동방향 결정
	bool IsMoveable = false;
	IsMoveable = InitPlayerMove(PlayerMoveDir);

	if (IsMoveable) {
		CurTurnType = TurnType::Move_AI_Select;
		return;
	}
	if (!IsMoveable) {
		CurTurnType = TurnType::Player_Select;
		return;
	}

};

bool ATurnManager::InitPlayerMove(FVector2D moveVector)
{
	Player->SetTargetLocation(Player->GetStartLocation() + moveVector * 72);
	FIntPoint TargetTile = Player->GetTargetTile();
	TileType TargetTileType = Dungeon->GetTileType(TargetTile.X, TargetTile.Y);
	//앞이 벽이면
	if (TileType::WALL == TargetTileType) {
		Player->SetTargetLocation(Player->GetActorLocation()); 
		return false;
	}
	/*else if (TileType::WATER == TargetTileType) {

	}*/
	//앞에 몬스터가 있으면 코드 추가해야댐
	

	Player->SetStartLocation(Player->GetActorLocation());
	Player->ResetCurDuration();
	return true;
}


