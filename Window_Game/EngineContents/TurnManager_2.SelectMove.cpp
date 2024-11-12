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
	//���� ���̸�
	if (TileType::WALL == TargetTileType) {
		Player->SetTargetLocation(Player->GetActorLocation()); 
		return false;
	}
	/*else if (TileType::WATER == TargetTileType) {

	}*/
	//�տ� ���Ͱ� ������ �ڵ� �߰��ؾߴ�
	

	Player->SetStartLocation(Player->GetActorLocation());
	Player->ResetCurDuration();
	return true;
}


