#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineRandom.h>


#include "Player.h"
#include "Dungeon.h"
#include "Partner.h"


ATurnManager::ATurnManager()
{

}

ATurnManager::~ATurnManager()
{

}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();
	AActor* PlayerActor = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(PlayerActor);
	SetSpawnPos();
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetActorLocation());
	IdleMaps.insert({1.0f,Partner});

	CurTurnType = TurnType::Player_Select;

}

void ATurnManager::Tick(float _DeltaTime)
{

	
	switch (CurTurnType)
	{
	case TurnType::Player_Select:
		PlayerSelect();
		break;
	case TurnType::Player_Select_Move:
		SelectMove(PlayerInput);
		break;
	case TurnType::Player_Select_Skill:
		SelectSkill(PlayerInput);
		break;
	case TurnType::Player_Move:
		PlayerMove(_DeltaTime);
		break;
	case TurnType::Player_Skill:
		PlayerSkill(_DeltaTime);
		break;
	case TurnType::Move_AI_Select:
		PlayerMove_AISelect(_DeltaTime);
		break;
	case TurnType::Skill_AI_Select:
		PlayerSkill_AISelect(_DeltaTime);
		break;
	case TurnType::AI_Move:
		AIMove(_DeltaTime);
		break;
	case TurnType::AI_Skill:
		AISkill(_DeltaTime);
		break;
	}
}

void ATurnManager::SetSpawnPos()
{
	UEngineRandom Random;
	// player pos
	int RoomCount = Dungeon->GetDungeonData()->Rooms.size();
	int Index = Random.RandomInt(0, RoomCount - 1);
	FVector2D RoomLocation = Dungeon->GetDungeonData()->Rooms[Index].RoomTrans.Location;
	FVector2D RoomScale = Dungeon->GetDungeonData()->Rooms[Index].RoomTrans.Scale;
	FVector2D SpawnPos = FVector2D(Random.RandomInt(RoomLocation.X + 1, RoomLocation.X + RoomScale.X - 2), Random.RandomInt(RoomLocation.Y + 1, RoomLocation.Y + RoomScale.Y - 2));
	Player->SetActorLocation(SpawnPos * 72);

	// partner pos
	FVector2D PlayerPos = Player->GetActorLocation();
	FVector2D PosIndex = PlayerPos / 72;
	bool isSpawnPartner = false;
	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			TILETYPE TileType = Dungeon->GetDungeonData()->TileTypes[PosIndex.iY() + y][PosIndex.iX()+x];
			if (TILETYPE::GROUND == TileType && x != 0 && y != 0)
			{
				FVector2D PartnerPos = FVector2D(PlayerPos.X + x * 72, PlayerPos.Y + y * 72);
				Partner->SetActorLocation(PartnerPos);
				isSpawnPartner = true;
			}
		}
		if (isSpawnPartner)
		{
			break;
		}
	}

}






