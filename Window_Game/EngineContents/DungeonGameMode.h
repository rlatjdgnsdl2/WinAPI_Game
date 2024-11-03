#pragma once
#include "TileMap.h"
#include <EngineCore/GameMode.h>
//	Ό³Έν:
class ADungeonGameMode : public AGameMode
{
public:
	//	constrcuter, destructer
	ADungeonGameMode();
	virtual ~ADungeonGameMode();

	//	delete Function
	ADungeonGameMode(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode(ADungeonGameMode&& _Other) noexcept = delete;
	ADungeonGameMode& operator=(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode& operator=(ADungeonGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime)override;
	void LevelChangeStart() override;

protected:

private:
	ATileMap* Dungeon_Background;
	
};

