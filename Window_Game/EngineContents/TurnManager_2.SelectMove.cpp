#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Dungeon_BSP.h"
#include "MoveController.h"

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
	FVector2D PlayerLocation = Player->GetActorLocation();
	UMoveController* PlayerMove = Player->GetMoveController();
	PlayerMove->SetTargetLocation(PlayerLocation + moveVector * 72.0f);
	FIntPoint TargetTile = PlayerMove->GetTargetTile();
	TileType TargetTileType = Dungeon->GetTileType(TargetTile.X, TargetTile.Y);
	//	���� ���� �ƴϸ�
	if (TileType::GROUND != TargetTileType) {
		PlayerMove->SetTargetLocation(PlayerLocation);
		return false;
	}
	//	�տ� ���� ������ �̵��Ұ�
	for (APokemon* EnemyPokemon : EnemyCamp)
	{
		FVector2D EnemyLocation = EnemyPokemon->GetMoveController()->GetTargetLocation();
		if (PlayerMove->GetTargetLocation() == EnemyLocation) {
			PlayerMove->SetTargetLocation(PlayerLocation);
			return false;
		}
	}
	//	���� ���ǿ� �Ȱɷȴٸ�
	PlayerMove->ResetCurDuration();
	return true;
}


