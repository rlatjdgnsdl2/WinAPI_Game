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
	// 1. 턴매니저 생성
	if (nullptr == TurnManager) {
		TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	}
	//	2. 던전 생성
	if (nullptr == Dungeon) {

		ADungeon_BSP* NewDungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
		Dungeon = NewDungeon;
	}
	//	던전 이름 받아와서
	CurDungeonName = UGameDataManager::GetInst().GetSelectDungeon();
	//	던전 형태 생성
	Dungeon->Generate(CurDungeonName);
	//	턴매니저에게 던전전달
	TurnManager->SetDungeon(Dungeon);
	//	플레이어 연결
	if (nullptr == Player) {
		AActor* PlayerActor = GetWorld()->GetPawn();
		Player = dynamic_cast<APlayer*>(PlayerActor);
	}
	Player->SetPokemon("Mudkip");
	TurnManager->SetPlayer(Player);
	TurnManager->PushPlayerCamp(Player);
	//	파트너 생성
	if (nullptr == Partner) {
		Partner = GetWorld()->SpawnActor<APartner>();
	}
	Partner->SetPokemon("Vulpix");
	TurnManager->PushAllAIPokemon(Partner);
	TurnManager->PushPlayerCamp(Partner);

	//	적 생성 테스트코드
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




















