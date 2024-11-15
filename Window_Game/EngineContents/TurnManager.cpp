#include "PreCompile.h"
#include "TurnManager.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/EngineAPICore.h>

#include "Player.h"
#include "Partner.h"
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
	case TurnType::Open_Menu:
		OpenMenu();
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
		PlayerSkill();
		break;
	case TurnType::Move_AI_Select:
		Move_AISelect();
		break;
	case TurnType::Skill_AI_Select:
		Skill_AISelect();
		break;
	case TurnType::AI_Move:
		AIMove(_DeltaTime);
		break;
	case TurnType::AI_Skill:
		AISkill();
		break;

	}
}




void ATurnManager::InitSpawn()
{
	UEngineRandom Random;
	// Player Camp Spawn 
	{
		int MaxSize = static_cast<int>(Dungeon->GetRoomLocations().size());
		int Index = Random.RandomInt(0, MaxSize - 1);
		FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
		std::list<APokemon*>::iterator StartIter = PlayerCamp.begin();
		APokemon* FirstPokemon = *StartIter;
		FirstPokemon->SetActorLocation(RoomLocation);
		StartIter++;
		std::list<APokemon*>::iterator EndIter = PlayerCamp.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			bool IsSpawn = false;
			FIntPoint FirstTileIndex = FirstPokemon->GetCurTile();
			for (int y = -1; y <= 1; y++)
			{
				if (true == IsSpawn) {
					break;
				}
				for (int x = -1; x <= 1; x++)
				{
					if (x != 0 && y != 0) {
						TileType CheckTileType = Dungeon->GetTileType(FirstTileIndex.X + x, FirstTileIndex.Y + y);
						if (TileType::GROUND == CheckTileType) {
							CurPokemon->SetActorLocation({ (FirstTileIndex.X + x) * 72.0f, (FirstTileIndex.Y + y) * 72.0f });
							IsSpawn = true;
							break;
						}
					}
				}
			}
		}

	}
	//	Enemy Camp Spawn
	{
		std::list<APokemon*>::iterator StartIter = EnemyCamp.begin();
		std::list<APokemon*>::iterator EndIter = EnemyCamp.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			int MaxSize = static_cast<int>(Dungeon->GetRoomLocations().size());
			int Index = Random.RandomInt(0, MaxSize - 1);
			FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
			CurPokemon->SetActorLocation(RoomLocation);

		}
	}












}












