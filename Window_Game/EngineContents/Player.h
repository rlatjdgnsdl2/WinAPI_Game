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

	/*void BeginPlay() override;
	void Tick(float _DeltaTime) override;*/
	void LevelChangeStart() override;
	void LevelChangeEnd() override;

	/*void Idle(float _DeltaTime);
	void Walk(float _DeltaTime);*/
	void Attack(float _DeltaTime);

	class USpriteRenderer* GetSpriteRenderer() {
		return SpriteRenderer;
	}
	DIR GetDir() const
	{
		return CurDir;
	};
	void SetDir(DIR _dir) {
		CurDir = _dir;
	}
	FVector2D GetStartLocation() const
	{
		return StartLocation;
	}
	FVector2D GetTargetLocation() const
	{
		return TargetLocation;
	}
	FVector2D SetStartLocation(FVector2D _StartLocation)
	{
		StartLocation = _StartLocation;
		return StartLocation;
	}
	FVector2D SetTargetLocation(FVector2D _TargetLocation)
	{
		TargetLocation = _TargetLocation;
		return TargetLocation;
	}


protected:

private:
	class USpriteRenderer* SpriteRenderer;
	DIR CurDir = DIR::Down;

	FVector2D StartLocation;
	FVector2D TargetLocation;

	float Speed = 2.0f;
	float CurDuration = 0.0f;

	void AnimationSetting();

	STATE CurState = STATE::IDLE;



};

