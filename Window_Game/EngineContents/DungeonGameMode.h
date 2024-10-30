#pragma once
#include <EngineCore/GameMode.h>
#include "Dungeon.h"

//	����:
class ADungeonGameMode :public AGameMode
{
public:
	//	constrcuter, destructer
	ADungeonGameMode();
	~ADungeonGameMode();

	//	delete Function
	ADungeonGameMode(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode(ADungeonGameMode&& _Other) noexcept = delete;
	ADungeonGameMode& operator=(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode& operator=(ADungeonGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;

	void GenerateDungeon(class UDungeonGenAlgorithm* _SelectAlgo);

protected:
	

private:
	ADungeon Dungeon;
	std::map<std::string, class UDungeonGenAlgorithm*> AlgoMaps;

};

