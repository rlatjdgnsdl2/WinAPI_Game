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
	PokemonPool.resize(10, nullptr);
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
	TurnManager->SetDungeon(Dungeon);

	DungeonInfo CurDungeonInfo = UGameDataManager::GetInst().GetDungeonInfo(CurDungeonName);
	int MaxCount = CurDungeonInfo.Pokemons_In_Dongeon.size() - 1;
	UEngineRandom Random;

		//3. 몬스터생성
	for (int i = 0; i < PokemonPool.size(); i++)
	{
		if (nullptr == PokemonPool[i]) {
			APokemon* NewPokemon = GetWorld()->SpawnActor<APokemon>();
			PokemonPool[i] = NewPokemon;
		}
		int Index = Random.RandomInt(0,MaxCount);
		//	던전에 사는 포켓몬으로 설정
		PokemonPool[i]->SetPokemon(CurDungeonInfo.Pokemons_In_Dongeon[Index]);

	}
	TurnManager->SetAllPokemon(PokemonPool);
}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	Dungeon->RoomClear();
}




















