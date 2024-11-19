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

	if (!IsMoveable) {
		CurTurn = TurnType::Player_Select;
		return;
	}
	CurTurn = TurnType::Move_AI_Select;
	return;
};

bool ATurnManager::InitPlayerMove(FVector2D moveVector)
{
	if (Player == nullptr) {
		return false;
	}

	FVector2D PlayerLocation = Player->GetActorLocation();
	Player->SetTargetLocation(PlayerLocation + moveVector * 72.0f);
	FIntPoint TargetTile = Player->GetTargetTile();
	TileType TargetTileType = Dungeon->GetTileType(TargetTile.X, TargetTile.Y);
	//	앞이 땅이 아니면
	if (TileType::GROUND != TargetTileType) {
		Player->SetTargetLocation(PlayerLocation);
		return false;
	}
	//	앞에 적이 있으면 이동불가
	for (APokemon* EnemyPokemon : EnemyCamp)
	{
		FVector2D EnemyLocation = EnemyPokemon->GetTargetLocation();
		if (Player->GetTargetLocation() == EnemyLocation) {
			Player->SetTargetLocation(PlayerLocation);
			return false;
		}
	}
	//	위에 조건에 안걸렸다면
	Player->ResetCurDuration();
	return true;
}




