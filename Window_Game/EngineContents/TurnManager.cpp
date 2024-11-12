#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/EngineCoreDebug.h>


#include "Player.h"
#include "Dungeon_BSP.h"




ATurnManager::ATurnManager() :CurTurnType{ TurnType::Player_Select }, PlayerDir{ DIR::Down }, PlayerInput{ 0 }
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
	//	카메라 피봇설정
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(WindowSize.Half()*-1.0f);
	SetSpawn();
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetActorLocation());
	PathFinder.SetData(this);
	PushPlayerCamp(Player);
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




void ATurnManager::SetSpawn()
{
	UEngineRandom Random;

	// Player Spawn
	int MaxSize = static_cast<int>(Dungeon->GetRoomLocations().size());
	int Index = Random.RandomInt(0, MaxSize - 1);
	FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
	GetWorld()->GetPawn()->SetActorLocation(RoomLocation);


	//	몬스터 Spawn
	std::list<APokemon*>::iterator StartIter = AllAIPokemon.begin();
	std::list<APokemon*>::iterator EndIter = AllAIPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		bool IsSpawnable = false;
		while (!IsSpawnable) {
			int Index = Random.RandomInt(0, MaxSize - 1);
			FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
			if (RoomLocation != Player->GetActorLocation()) {
				CurPokemon->SetActorLocation(RoomLocation);
				FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
				CurPokemon->SetStartLocation(CurPokemonLocation);
				CurPokemon->SetStartLocation(CurPokemonLocation);
				
				IsSpawnable = true;
			}
		}
	}

}










