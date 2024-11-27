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
#include "UIManager.h"
#include "Item.h"
#include "Fade.h"
#include "Text.h"



ATurnManager::ATurnManager() :Dungeon(nullptr), Player(nullptr), UIManager(nullptr), DungeonUI(nullptr), CurTurn(TurnType::Player_Select), PreTurn(TurnType::Player_Select), PlayerInput(-1)
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
	Fade = GetWorld()->SpawnActor<AFade>();
	DungeonName = GetWorld()->SpawnActor<AText>();

	DungeonName->SetActorLocation(WindowSize.Half()+FVector2D::LEFT*80);

}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();
	DungeonName->SetActive(true);
	DungeonName->SetString(std::format("{}F {}", Dungeon->GetCurFloor(), UGameDataManager::GetInst().GetSelectDungeon()), Color::White);
	DungeonName->SetOrder(ERenderOrder::UI_FadeText);
	Fade->Reset();
	PathFinder.SetData(Dungeon);
	PushPlayerCamp(Player);
	Partner = GetWorld()->SpawnActor<APartner>();
	UIManager->SetPartner(Partner);
	PushAllAIPokemon(Partner);
	PushPlayerCamp(Partner);
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
	CurTurn = TurnType::Fade;
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
	case TurnType::Fade:
		CurDuration += _DeltaTime;
		if (CurDuration < 2.5f)
		{
			DungeonName->ShowText(0.0f);
			return;
		}
		Fade->FadeOut();
		DungeonName->SetActive(false);
		CurDuration = 0.0f;
		CurTurn = TurnType::Player_Select;
		return;
	case TurnType::Player_Select:
		PlayerSelect(_DeltaTime);
		return;
	case TurnType::Open_UI:
		OpenMenu();
		return;
	case TurnType::Player_Select_Move:
		SelectMove();
		return;
	case TurnType::Player_Select_Skill:
		SelectSkill();
		return;
	case TurnType::Player_Move:
		PlayerMove(_DeltaTime);
		return;
	case TurnType::Player_Skill_Start:
		PlayerSkillStart();
		return;
	case TurnType::Player_Skill:
		PlayerSkill(_DeltaTime);
		return;
	case TurnType::Player_Skill_End:
		PlayerSkillEnd();
		return;
	case TurnType::Move_AI_Select:
		Move_AISelect();
		return;
	case TurnType::Skill_AI_Select:
		Skill_AISelect();
		return;
	case TurnType::AI_Move:
		AIMove(_DeltaTime);
		return;
	case TurnType::AI_Skill_Start:
		AISkillStart();
		return;
	case TurnType::AI_Skill:
		AISkill(_DeltaTime);
		return;
	case TurnType::AI_Skill_End:
		AISkillEnd();
		return;
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
	bool IsSpawnable = false;
	while (true) {
		int SpawnIndex = Random.RandomInt(0, SpawnMaxSize - 1);
		FVector2D RoomLocation = Dungeon->GetRoomLocations()[SpawnIndex];
		for (APokemon* CurPokemon : AllAIPokemon)
		{
			if (RoomLocation == CurPokemon->GetActorLocation()) {
				IsSpawnable = false;
				break;
			}
			IsSpawnable = true;
		}
		if (IsSpawnable) {
			NewEnemy->SetActorLocation(RoomLocation);
			NewEnemy->SetTargetLocation(Player->GetActorLocation());
			PushAllAIPokemon(NewEnemy);
			PushEnemyCamp(NewEnemy);
			break;
		}
	}
}
















