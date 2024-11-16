#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "GameDataManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Dungeon_BSP.h"
#include "TurnManager.h"


ADungeonGameMode::ADungeonGameMode()
{

}

ADungeonGameMode::~ADungeonGameMode()
{

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
	// 1. �ϸŴ��� ����
	if (nullptr == TurnManager) {
		TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	}
	//	2. ���� ����
	if (nullptr == Dungeon) {

		ADungeon_BSP* NewDungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
		Dungeon = NewDungeon;
	}
	//	���� �̸� �޾ƿͼ�
	CurDungeonName = UGameDataManager::GetInst().GetSelectDungeon();
	//	���� ���� ����
	Dungeon->Generate(CurDungeonName);
	//	�ϸŴ������� ��������
	TurnManager->SetDungeon(Dungeon);
	//	�÷��̾� ����
	if (nullptr == Player) {
		AActor* PlayerActor = GetWorld()->GetPawn();
		Player = dynamic_cast<APlayer*>(PlayerActor);
	}
	Player->SetPokemon("Mudkip");
	TurnManager->SetPlayer(Player);
	TurnManager->PushPlayerCamp(Player);


	//	��Ʈ�� ����
	{
		APlayer* Partner = GetWorld()->SpawnActor<APlayer>();
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




















