#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "GameDataManager.h"
#include "Player.h"
#include "Partner.h"
#include "Enemy.h"
#include "Dungeon_BSP.h"
#include "TurnManager.h"


ADungeonGameMode::ADungeonGameMode()
{

}

ADungeonGameMode::~ADungeonGameMode()
{

}


void ADungeonGameMode::BeginPlay()
{
	Super::BeginPlay();
	ATurnManager* TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	ADungeon_BSP* Dungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
	TurnManager->SetDungeon(Dungeon);
	TurnManager->SetPlayer(dynamic_cast<APlayer*>(GetWorld()->GetPawn()));
}


void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::GetInst().IsDown('G'))
	{
		UEngineAPICore::GetCore()->OpenLevel("DungeonSelectLevel");
	}
}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	//	���� �̸� �޾ƿͼ�
	CurDungeonName = UGameDataManager::GetInst().GetSelectDungeon();
	//	���� ���� ����
	Dungeon->Generate(CurDungeonName);

	TurnManager->SetDungeon(Dungeon);

	Player->SetPokemon("Mudkip");
	TurnManager->SetPlayer(Player);
	TurnManager->PushPlayerCamp(Player);


	//	��Ʈ�� ����
	{
		APartner* Partner = GetWorld()->SpawnActor<APartner>();
		Partner->SetPokemon("Vulpix");
		TurnManager->PushAllAIPokemon(Partner);
		TurnManager->PushPlayerCamp(Partner);
	}
	//	�� ����
	{
		AEnemy* Enemy = GetWorld()->SpawnActor<AEnemy>();
		Enemy->SetPokemon("Kabuto");
		TurnManager->PushEnemyCamp(Enemy);
		TurnManager->PushAllAIPokemon(Enemy);
	}

	{
		AEnemy* Enemy = GetWorld()->SpawnActor<AEnemy>();
		Enemy->SetPokemon("Shellder");
		TurnManager->PushEnemyCamp(Enemy);
		TurnManager->PushAllAIPokemon(Enemy);
	}

	{
		AEnemy* Enemy = GetWorld()->SpawnActor<AEnemy>();
		Enemy->SetPokemon("Shellos");
		TurnManager->PushEnemyCamp(Enemy);
		TurnManager->PushAllAIPokemon(Enemy);
	}

	{
		AEnemy* Enemy = GetWorld()->SpawnActor<AEnemy>();
		Enemy->SetPokemon("Corsola");
		TurnManager->PushEnemyCamp(Enemy);
		TurnManager->PushAllAIPokemon(Enemy);
	}
}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	Dungeon->RoomClear();
}




















