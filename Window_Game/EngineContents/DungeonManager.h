#pragma once
#include <EngineBase/Object.h>
#include "Dungeon.h"


//	설명: 던전생성기
class UDungeonManager :UObject
{
public:
	//	constrcuter, destructer
	UDungeonManager();
	~UDungeonManager();

	//	delete Function
	UDungeonManager(const UDungeonManager& _Other) = delete;
	UDungeonManager(UDungeonManager&& _Other) noexcept = delete;
	UDungeonManager& operator=(const UDungeonManager& _Other) = delete;
	UDungeonManager& operator=(UDungeonManager&& _Other) noexcept = delete;

	void GenerateDungeon(class UDungeonGenAlgorithm* _SelectAlgo);

protected:

private:
	ADungeon Dungeon;
	std::map<std::string, class UDungeonGenAlgorithm*> AlgoMaps;

};

