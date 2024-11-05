#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "TileMap.h"




std::vector<std::vector<FVector2D>> ADungeonGameMode::AllGrounds;
ADungeonGameMode::ADungeonGameMode()
{


}

ADungeonGameMode::~ADungeonGameMode()
{

}

void ADungeonGameMode::BeginPlay()
{
	Super::BeginPlay();


}
void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	if (nullptr == Dungeon) {

		Dungeon = GetWorld()->SpawnActor<ATileMap>();
	}
	GenerateDungeon();
}


void ADungeonGameMode::GenerateDungeon()
{
	Dungeon->SetAllWall();
	Dungeon->SetHallWay();
	Dungeon->SetRoom();
	Dungeon->SetBorderWall();
	Dungeon->CheckTile();
}



void ADungeonGameMode::SetCurDungeonName(std::string_view _DungeonName)
{
	CurDungeonName = _DungeonName;
}







