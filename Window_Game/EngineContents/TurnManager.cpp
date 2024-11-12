#include "PreCompile.h"
#include "TurnManager.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/EngineAPICore.h>

#include "Player.h"
#include "Dungeon_BSP.h"
#include "GameDataManager.h"




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
	//	카메라 피봇설정
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(WindowSize.Half() * -1.0f);

	// 처음 스폰위치
	InitSpawn();
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetActorLocation());
	PathFinder.SetData(Dungeon);

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
		SelectMove();
		break;
	case TurnType::Player_Select_Skill:
		SelectSkill();
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




void ATurnManager::InitSpawn()
{
	UEngineRandom Random;
	// Player Spawn 생성된 방중에 랜덤한 위치에 
	int MaxSize = static_cast<int>(Dungeon->GetRoomLocations().size());
	int Index = Random.RandomInt(0, MaxSize - 1);
	FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
	Player->SetActorLocation(RoomLocation);
	PushPlayerCamp(Player);
	//	동료들은 플레이어 옆에 소환되기
}

void ATurnManager::SpawnEnemyPokemon()
{
	APokemon* NewEnemyPokemon = GetWorld()->SpawnActor<APokemon>();
	
}










