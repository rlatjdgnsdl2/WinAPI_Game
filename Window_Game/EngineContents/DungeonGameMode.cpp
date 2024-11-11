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

	// �ϸŴ��� ����
	if (nullptr == TurnManager) {
		TurnManager = GetWorld()->SpawnActor<ATurnManager>();
	}

	//	��������
	if (nullptr == TurnManager->Dungeon) {

		ADungeon_BSP* NewDungeon = GetWorld()->SpawnActor<ADungeon_BSP>();
		TurnManager->Dungeon = NewDungeon;
	}
	//	�����̸� �޾ƿͼ�
	CurDungeonName = UGameDataManager::GetInst().GetSelectDungeon();
	//	��������
	TurnManager->Dungeon->Generate(CurDungeonName);
	//	������ ��� ���ϸ� �޾ƿͼ�
	std::vector<std::string> Pokemons_In_Dungeon = UGameDataManager::GetInst().GetDungeonInfo(CurDungeonName).Pokemons_In_Dongeon;
	UEngineRandom Random;
	int MaxIndex = static_cast<int>(Pokemons_In_Dungeon.size());
	//	����
	for (int i = 0; i < 3; i++)
	{
		int Index = Random.RandomInt(0, MaxIndex-1);
		//	�̷��� LevelChage���� ��� �����Ǵµ� levelend�� destroy�ؾ��ϳ�?
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




















