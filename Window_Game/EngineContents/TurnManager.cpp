#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/EngineCoreDebug.h>


#include "Player.h"
#include "Dungeon_BSP.h"
#include "Partner.h"
#include "Enemy_01.h"


ATurnManager::ATurnManager()
{

}

ATurnManager::~ATurnManager()
{

}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();

	//	MainPawn 연결
	AActor* PlayerActor = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(PlayerActor);
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(true);

	//	Spawn위치 설정
	SetSpawnPos();
	//	초기화
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetActorLocation());
	//	캠프설정
	PlayerCamp.push_back(Player);
	PlayerCamp.push_back(Partner);
	CurTurnType = TurnType::Player_Select;

}

void ATurnManager::Tick(float _DeltaTime)
{

	Super::Tick(_DeltaTime);
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
		Move_AISelect(_DeltaTime);
		break;
	case TurnType::Skill_AI_Select:
		Skill_AISelect(_DeltaTime);
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
	int MaxSize = Dungeon->GetRoomLocations().size()-1;
	int RandomInex = Random.RandomInt(0, MaxSize);
	FVector2D RoomLocation = Dungeon->GetRoomLocations()[RandomInex];
	Player->SetActorLocation(RoomLocation);

	//partner pos
	FVector2D PlayerPos = Player->GetActorLocation();
	FVector2D PosIndex = PlayerPos / 72;
	bool IsSpawnPartner = false;
	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			if (IsSpawnPartner)
			{
				break;
			}
			TileType TargetTileType = Dungeon->GetTileType(PosIndex.iX()+x, PosIndex.iY()+y);
			if (TileType::GROUND == TargetTileType && x != 0 && y != 0)
			{
				FVector2D PartnerPos = FVector2D(PlayerPos.X + x * 72, PlayerPos.Y + y * 72);
				Partner->SetActorLocation(PartnerPos);
				IsSpawnPartner = true;
			}
		}
	}

	//// TestSpawn monster
	////TestEnemy->SetActorLocation(PlayerPos+FVector2D(144,144));

}








