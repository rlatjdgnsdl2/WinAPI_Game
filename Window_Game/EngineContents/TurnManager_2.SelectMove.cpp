#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Dungeon_BSP.h"
#include "MoveController.h"

//	Select_Move단계
void ATurnManager::SelectMove()
{
	// Player 이동방향 결정
	bool IsMoveable = false;
	IsMoveable = InitPlayerMove(PlayerMoveDir);

	if (!IsMoveable) {
		CurTurn = TurnType::Player_Select;
		return;
	}
	CurTurn = TurnType::Move_AI_Select;
	return;
};

bool ATurnManager::InitPlayerMove(FVector2D moveVector)
{
	FVector2D PlayerLocation = Player->GetActorLocation();
	UMoveController* PlayerMove = Player->GetMoveController();
	PlayerMove->SetTargetLocation(PlayerLocation + moveVector * 72.0f);
	FIntPoint TargetTile = PlayerMove->GetTargetTile();
	TileType TargetTileType = Dungeon->GetTileType(TargetTile.X, TargetTile.Y);
	//	앞이 땅이 아니면
	if (TileType::GROUND != TargetTileType) {
		PlayerMove->SetTargetLocation(PlayerLocation);
		return false;
	}
	//	앞에 적이 있으면 이동불가
	for (APokemon* EnemyPokemon : EnemyCamp)
	{
		FVector2D EnemyLocation = EnemyPokemon->GetMoveController()->GetTargetLocation();
		if (PlayerMove->GetTargetLocation() == EnemyLocation) {
			PlayerMove->SetTargetLocation(PlayerLocation);
			return false;
		}
	}
	//	위에 조건에 안걸렸다면
	PlayerMove->ResetCurDuration();
	return true;
}


