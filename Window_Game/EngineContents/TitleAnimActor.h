#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATitleAnimActor :public AActor
{
public:
	//	constrcuter, destructer
	ATitleAnimActor();
	virtual ~ATitleAnimActor();

	//	delete Function
	ATitleAnimActor(const ATitleAnimActor& _Other) = delete;
	ATitleAnimActor(ATitleAnimActor&& _Other) noexcept = delete;
	ATitleAnimActor& operator=(const ATitleAnimActor& _Other) = delete;
	ATitleAnimActor& operator=(ATitleAnimActor&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	class USpriteRenderer* SpriteRenderer;
	float test;

};

