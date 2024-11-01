#pragma once
#include <EngineCore/GameMode.h>


//	Ό³Έν:
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
	

	void GenerateDungeon(std::string_view _SelectAlgo);

protected:
	
private:
	Dungeon Dungeon;
	std::map<std::string, class UDungeonGenAlgorithm*> AlgoMaps;

};

