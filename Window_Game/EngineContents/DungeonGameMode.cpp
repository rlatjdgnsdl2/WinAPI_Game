#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/Level.h>

#include "Player.h"
#include "GameDataManager.h"
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

	// 턴매니저 생성
	if (nullptr == TurnManager) {
		TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	}

	//	던전생성
	if (nullptr == TurnManager->Dungeon) {

		ADungeon_BSP* NewDungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
		TurnManager->Dungeon = NewDungeon;
	}
	//	던전이름 받아와서
	CurDungeonName = UGameDataManager::GetInst().GetSelectDungeon();
	//	던전생성
	TurnManager->Dungeon->Generate(CurDungeonName);
	//	던전에 사는 포켓몬 받아와서
	std::vector<std::string> Pokemons_In_Dungeon = UGameDataManager::GetInst().GetDungeonInfo(CurDungeonName).Pokemons_In_Dongeon;
	UEngineRandom Random;
	int MaxIndex = static_cast<int>(Pokemons_In_Dungeon.size());
	//	생성
	for (int i = 0; i < 3; i++)
	{
		int Index = Random.RandomInt(0, MaxIndex-1);
		//	이러면 LevelChage마다 계속 생성되는데 levelend때 destroy해야하나?
		APokemon* NewPokemon = GetWorld()->SpawnActor<APokemon>(Pokemons_In_Dungeon[Index]);
		TurnManager->PushAllPokemon(NewPokemon);
		TurnManager->PushEnemy(NewPokemon);
	}
}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	TurnManager->Dungeon->RoomLocationClear();
	TurnManager->AllClear();
}




















