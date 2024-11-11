#pragma once
#include <EngineCore/GameMode.h>

//	����:
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


protected:

private:
	class USpriteRenderer* SpriteRenderer;

};

