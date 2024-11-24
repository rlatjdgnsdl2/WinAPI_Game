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
	void LevelChangeStart()override;
	void LevelChangeEnd()override;
	void Tick(float _DeltaTime)override;



protected:

private:
	class USpriteRenderer* WorldMapRenderer;
	std::map<std::string, FVector2D>DungeonMaps;
	std::map<std::string, FVector2D>::iterator DungeonMapStartIter;
	std::map<std::string, FVector2D>::iterator DungeonMapEndIter;

	bool IsNextLevel = false;

	class AFade* Fade = nullptr;
	float CurDuration = 0.0f;

	class ABox* DungeonNameBox;
	class AText* DungeonNameRenderer;
};

