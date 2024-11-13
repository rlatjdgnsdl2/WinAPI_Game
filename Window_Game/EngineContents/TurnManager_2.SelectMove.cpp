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
	Player->SetTargetLocation(Player->GetActorLocation() + moveVector * 72);
	FIntPoint TargetTile = Player->GetTargetTile();
	TileType TargetTileType = Dungeon->GetTileType(TargetTile.X, TargetTile.Y);
	//���� ���̸�
	if (TileType::GROUND != TargetTileType) {
		Player->SetTargetLocation(Player->GetActorLocation());
		return false;
	}
	//�տ� ���Ͱ� ������ 
	std::list<APokemon*>::iterator StartIter = EnemyCamp.begin();
	std::list<APokemon*>::iterator EndIter = EnemyCamp.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* EnemyPokemon = *StartIter;
		FVector2D EnemyLocation = EnemyPokemon->GetActorLocation();
		if (Player->GetTargetLocation() == EnemyLocation) {
			Player->SetTargetLocation(Player->GetActorLocation());
			return false;
		}
	}
	//	���� ���ǿ� �Ȱɷȴٸ�
	Player->SetStartLocation(Player->GetActorLocation());
	Player->ResetCurDuration();
	return true;
}


