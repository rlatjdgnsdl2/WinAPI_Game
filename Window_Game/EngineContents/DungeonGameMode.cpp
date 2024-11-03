#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>

#include "Dungeon.h"
#include "DungeonGenerator.h"
#include "TutorialGenerator.h"

std::string ADungeonGameMode::CurGeneratorName;
std::string ADungeonGameMode::CurDungeonName;
ADungeonGameMode::ADungeonGameMode() 
{
	UTutorialGenerator* TutorialGenerator = new UTutorialGenerator();
	GeneratorMaps.insert({"Tutorial",TutorialGenerator});
}

ADungeonGameMode::~ADungeonGameMode() 
{
	std::map<std::string, UDungeonGenerator* > ::iterator StartIter = GeneratorMaps.begin();
	std::map<std::string, UDungeonGenerator* > ::iterator EndIter = GeneratorMaps.end();
	for (; StartIter != EndIter; StartIter++)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
		GeneratorMaps.clear();
	}
}
void ADungeonGameMode::BeginPlay()
{
	Super::BeginPlay();
	Dungeon = GetWorld()->SpawnActor<ADungeon>();

}
void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeEnd();
	GenerateDungeon(CurDungeonName,CurGeneratorName);
	
}

void ADungeonGameMode::GenerateDungeon(std::string_view _DungeonName, std::string_view _GeneratorName)
{
	UDungeonGenerator* DungeonGenerator = GeneratorMaps[_GeneratorName.data()];
	DungeonGenerator->GenerateDungeon(Dungeon);
}

void ADungeonGameMode::SetCurDungeonName(std::string_view _DungeonName)
{
	CurDungeonName = _DungeonName.data();
}

void ADungeonGameMode::SetCurGeneratorName(std::string_view _GeneratorName)
{
	CurGeneratorName = _GeneratorName.data();
}
