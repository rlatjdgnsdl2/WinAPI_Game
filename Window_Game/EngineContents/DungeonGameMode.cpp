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
	TurnManager->SetPlayer(Player);
	TurnManager->PushPlayerCamp(Player);
	//	파트너 생성
	if (nullptr == Partner) {
		Partner = GetWorld()->SpawnActor<APartner>();
	}
	TurnManager->PushPlayerCamp(Partner);



}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	Dungeon->RoomClear();
}




















