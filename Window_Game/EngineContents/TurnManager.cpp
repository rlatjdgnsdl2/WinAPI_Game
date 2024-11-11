#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>


#include "Player.h"
#include "Dungeon_BSP.h"
#include "Partner.h"



ATurnManager::ATurnManager() :CurTurnType{ TurnType::Player_Select }, PlayerDir{ DIR::Down }, PlayerInput{0}
{

}

ATurnManager::~ATurnManager()
{

}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();
	//	MainPawn ¿¬°á
	SetPlayer();
	PlayerCamp.push_back(Player);
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetActorLocation());

	SetSpawnPos();
	
	
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
	case TurnType::DebugMode:
		DebugMode(_DeltaTime);
		break;

	}
}

void ATurnManager::SetPlayer()
{
	AActor* PlayerActor = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(PlayerActor);
}


void ATurnManager::SetSpawnPos()
{
	UEngineRandom Random;
	// player pos
	int MaxSize = static_cast<int>(Dungeon->GetRoomLocations().size());
	int Index = Random.RandomInt(0, MaxSize - 1);
	FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
	GetWorld()->GetPawn()->SetActorLocation(RoomLocation);


	std::vector<APokemon*>::iterator StartIter = EnemyCamp.begin();
	std::vector<APokemon*>::iterator EndIter = EnemyCamp.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		bool IsSpawnable = false;
		while (!IsSpawnable) {
			int Index = Random.RandomInt(0, MaxSize - 1);
			FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
			if (RoomLocation != Player->GetActorLocation()) {
				CurPokemon->SetActorLocation(RoomLocation);
				IsSpawnable = true;
			}
		}
	}

}










