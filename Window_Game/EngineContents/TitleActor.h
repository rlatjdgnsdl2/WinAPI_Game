#pragma once
#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATitleActor : public AActor
{
public:
	//	constrcuter, destructer
	ATitleActor();
	~ATitleActor();

	//	delete Function
	ATitleActor(const ATitleActor& _Other) = delete;
	ATitleActor(ATitleActor&& _Other) noexcept = delete;
	ATitleActor& operator=(const ATitleActor& _Other) = delete;
	ATitleActor& operator=(ATitleActor&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	

protected:

private:
	class USpriteRenderer* SpriteRenderer;
	float test = 0.0f;
	bool IsPlayAnim = false;

};

