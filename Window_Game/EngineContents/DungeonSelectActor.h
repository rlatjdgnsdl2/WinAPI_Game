#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
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

	virtual void Tick(float _DeltaTime)override;
	virtual void LevelChangeStart() override;

	

protected:

private:
	class USpriteRenderer* SpriteRenderer;
	std::vector<class USpriteRenderer*> TextRenderers;

};

