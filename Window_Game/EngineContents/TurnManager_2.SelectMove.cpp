#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Dungeon_BSP.h"


//	Select_Move�ܰ�
void ATurnManager::SelectMove()
{
	// Player �̵����� ����
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
	//	���� ���� �ƴϸ�
	if (TileType::GROUND != TargetTileType) {
		Player->SetTargetLocation(PlayerLocation);
		return false;
	}
	//	�տ� ���� ������ �̵��Ұ�
	for (APokemon* EnemyPokemon : EnemyCamp)
	{
		FVector2D EnemyLocation = EnemyPokemon->GetTargetLocation();
		if (Player->GetTargetLocation() == EnemyLocation) {
			Player->SetTargetLocation(PlayerLocation);
			return false;
		}
	}
	//	���� ���ǿ� �Ȱɷȴٸ�
	Player->ResetCurDuration();
	return true;
}




