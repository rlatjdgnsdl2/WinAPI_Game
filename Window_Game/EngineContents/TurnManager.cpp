#include "PreCompile.h"
#include "TurnManager.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/EngineAPICore.h>

#include "Player.h"
#include "Partner.h"
#include "Enemy.h"
#include "Dungeon_BSP.h"
#include "GameDataManager.h"
#include "BasicUI.h"



ATurnManager::ATurnManager() :Dungeon(nullptr), Player(nullptr), BasicUI(nullptr), DungeonUI(nullptr), CurTurn(TurnType::Player_Select), PreTurn(TurnType::Player_Select), PlayerInput(-1)
{

}

ATurnManager::~ATurnManager()
{

}

void ATurnManager::BeginPlay()
{
	Super::BeginPlay();
	//	카메라 피봇
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(WindowSize.Half() * -1.0f);
}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();
	PathFinder.SetData(Dungeon);
	PushPlayerCamp(Player);
	// 처음 스폰위치
	Dungeon->Generate();
	InitSpawn();

	SpawnEnemy();
	SpawnEnemy();
	SpawnEnemy();
	SpawnEnemy();
	SpawnEnemy();
	SpawnEnemy();
	SpawnEnemy();

	Player->SetTargetLocation(Player->GetActorLocation());

	CurTurn = TurnType::Player_Select;
}

void ATurnManager::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	for (APokemon* Pokemon : AllAIPokemon)
	{
		Pokemon->Destroy();
	}
	AllAIPokemon.clear();
	PlayerCamp.clear();
	EnemyCamp.clear();
	MovePokemon.clear();
	SkillPokemon.clear();
}

void ATurnManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	switch (CurTurn)
	{
	case TurnType::Player_Select:
		PlayerSelect(_DeltaTime);
		break;
	case TurnType::Open_UI:
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
	case TurnType::Player_Skill_Start:
		PlayerSkillStart();
		break;
	case TurnType::Player_Skill:
		PlayerSkill();
		break;
	case TurnType::Player_Skill_End:
		PlayerSkillEnd();
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
	case TurnType::AI_Skill_Start:
		AISkillStart();
		break;
	case TurnType::AI_Skill:
		AISkill();
		break;
	case TurnType::AI_Skill_End:
		AISkillEnd();
		break;
	}
}


void ATurnManager::InitSpawn()
{
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
			FIntPoint FirstTileIndex = FirstPokemon->GetTile();
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
}
void ATurnManager::SpawnEnemy()
{
	std::string EnemyName = UGameDataManager::GetInst().GetPokemonInDungeon();
	int EnemyLevel = UGameDataManager::GetInst().GetEnemyPokemonLevel();
	AEnemy* NewEnemy = GetWorld()->SpawnActor<AEnemy>(EnemyName, EnemyLevel);


	int SpawnMaxSize = static_cast<int>(Dungeon->GetRoomLocations().size());
	int SpawnIndex = Random.RandomInt(0, SpawnMaxSize - 1);
	FVector2D RoomLocation = Dungeon->GetRoomLocations()[SpawnIndex];
	NewEnemy->SetActorLocation(RoomLocation);
	PushAllAIPokemon(NewEnemy);
	PushEnemyCamp(NewEnemy);
}













