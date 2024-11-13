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
	if (nullptr == Partner) {
		Partner = GetWorld()->SpawnActor<APartner>();
	}
	Partner->SetPokemon("Vulpix");
	TurnManager->PushAllAIPokemon(Partner);
	TurnManager->PushPlayerCamp(Partner);

	//	�� ���� �׽�Ʈ�ڵ�
	if (nullptr == Enemy01) {
		Enemy01 = GetWorld()->SpawnActor<AEnemy>();
	}
	Enemy01->SetPokemon("Kabuto");
	TurnManager->PushEnemyCamp(Enemy01);
	TurnManager->PushAllAIPokemon(Enemy01);

	//if (nullptr == Enemy02) {
	//	Enemy02 = GetWorld()->SpawnActor<AEnemy>();
	//}
	//Enemy02->SetPokemon("Kabuto");
	//TurnManager->PushEnemyCamp(Enemy02);
	//TurnManager->PushAllAIPokemon(Enemy02);

	//if (nullptr == Enemy03) {
	//	Enemy03 = GetWorld()->SpawnActor<AEnemy>();
	//}
	//Enemy03->SetPokemon("Kabuto");
	//TurnManager->PushEnemyCamp(Enemy03);
	//TurnManager->PushAllAIPokemon(Enemy03);

	//if (nullptr == Enemy04) {
	//	Enemy04 = GetWorld()->SpawnActor<AEnemy>();
	//}
	//Enemy04->SetPokemon("Kabuto");
	//TurnManager->PushEnemyCamp(Enemy04);
	//TurnManager->PushAllAIPokemon(Enemy04);





}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	Dungeon->RoomClear();
}




















