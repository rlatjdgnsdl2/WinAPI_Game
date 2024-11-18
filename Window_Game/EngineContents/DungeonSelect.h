#pragma once
#include <EngineCore/Actor.h>

//	����:
class ADungeonSelectActor : public AActor
{
public:
	//	constrcuter, destructer
	ADungeonSelectActor();
	virtual ~ADungeonSelectActor();

	//	delete Function
	ADungeonSelectActor(const ADungeonSelectActor& _Other) = delete;
	ADungeonSelectActor(ADungeonSelectActor&& _Other) noexcept = delete;
	ADungeonSelectActor& operator=(const ADungeonSelectActor& _Other) = delete;
	ADungeonSelectActor& operator=(ADungeonSelectActor&& _Other) noexcept = delete;

protected:

private:
	class USpriteRenderer* SpriteRenderer;
	

};
