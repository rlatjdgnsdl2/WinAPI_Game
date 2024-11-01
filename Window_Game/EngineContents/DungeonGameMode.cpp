#include "PreCompile.h"
#include "DungeonGameMode.h"


#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>

#include "TileMap.h"
ADungeonGameMode::ADungeonGameMode() 
{
	UEngineDirectory Tile;
	Tile.MoveParentToDirectory("Resources");
	Tile.Append("Dungeon");
	UImageManager::GetInst().LoadFolder(Tile.GetPathToString());

}

ADungeonGameMode::~ADungeonGameMode() 
{

}
void ADungeonGameMode::BeginPlay() 
{
	GetWorld()->SpawnActor<ATileMap>();
}
