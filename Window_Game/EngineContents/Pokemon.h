#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class APokemon :public AActor
{
public:
	//	constrcuter, destructer
	APokemon();
	virtual ~APokemon();

	//	delete Function
	APokemon(const APokemon& _Other) = delete;
	APokemon(APokemon&& _Other) noexcept = delete;
	APokemon& operator=(const APokemon& _Other) = delete;
	APokemon& operator=(APokemon&& _Other) noexcept = delete;

	class USpriteRenderer* GetSpriteRenderer() const {
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
	class USpriteRenderer* SpriteRenderer;
	DIR CurDir = DIR::Down;
	FVector2D StartLocation;
	FVector2D TargetLocation;
	virtual void AnimationSetting()=0;

private:

};

