#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class APlayer :public AActor
{
public:
	//	constrcuter, destructer
	APlayer();
	virtual ~APlayer();

	//	delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void BeginPlay()override;
	void Tick(float _DeltaTime) override;


protected:

private:
	class USpriteRenderer* SpriteRenderer;

	void KeyCheck(float _DeltaTime);
	float Speed = 100.0f;
	float curTime=0.0f;
	float moveTime = 1.0f;
};

