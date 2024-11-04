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

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



protected:

private:
	class USpriteRenderer* SpriteRenderer;

	STATE CurState = STATE::IDLE;
	DIR CurDir = DIR::DOWN;


	FVector2D StartLocation;
	FVector2D TargetLocation;
	float Speed = 2.0f;
	float CurDuration = 0.0f;
	


	void InitSetting();
	void AnimationSetting();
	void Idle(float _DeltaTime);
	void Walk(float _DeltaTime);
	

	

};

