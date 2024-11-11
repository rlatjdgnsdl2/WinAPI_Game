#pragma once
#include <EngineCore/GameMode.h>

//	Ό³Έν:
class ADungeonSelectGameMode : public AGameMode
{
public:
	//	constrcuter, destructer
	ADungeonSelectGameMode();
	virtual ~ADungeonSelectGameMode();

	//	delete Function
	ADungeonSelectGameMode(const ADungeonSelectGameMode& _Other) = delete;
	ADungeonSelectGameMode(ADungeonSelectGameMode&& _Other) noexcept = delete;
	ADungeonSelectGameMode& operator=(const ADungeonSelectGameMode& _Other) = delete;
	ADungeonSelectGameMode& operator=(ADungeonSelectGameMode&& _Other) noexcept = delete;

	void BeginPlay()override;
	void Tick(float _DeltaTime)override;

	void SetCamera();


protected:

private:
	class USpriteRenderer* SpriteRenderer;
	std::map<std::string, FVector2D>DungeonMaps;
	std::map<std::string, FVector2D>::iterator DungeonMapStartIter;
	std::map<std::string, FVector2D>::iterator DungeonMapEndIter;
};

