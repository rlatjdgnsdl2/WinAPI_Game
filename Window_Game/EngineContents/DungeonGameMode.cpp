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
	TurnManager->SetDungeon(Dungeon);

	DungeonInfo CurDungeonInfo = UGameDataManager::GetInst().GetDungeonInfo(CurDungeonName);
	int MaxCount = CurDungeonInfo.Pokemons_In_Dongeon.size() - 1;
	UEngineRandom Random;

		//3. ���ͻ���
	for (int i = 0; i < PokemonPool.size(); i++)
	{
		if (nullptr == PokemonPool[i]) {
			APokemon* NewPokemon = GetWorld()->SpawnActor<APokemon>();
			PokemonPool[i] = NewPokemon;
		}
		int Index = Random.RandomInt(0,MaxCount);
		//	������ ��� ���ϸ����� ����
		PokemonPool[i]->SetPokemon(CurDungeonInfo.Pokemons_In_Dongeon[Index]);

	}
	TurnManager->SetAllPokemon(PokemonPool);
}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	Dungeon->RoomClear();
}




















