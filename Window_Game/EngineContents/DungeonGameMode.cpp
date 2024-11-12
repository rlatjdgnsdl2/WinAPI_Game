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
}

void ADungeonGameMode::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	Dungeon->RoomClear();
}




















