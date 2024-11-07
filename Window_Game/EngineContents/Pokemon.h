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

	

	virtual void Idle();
	virtual void Move(float _DeltaTime);
	virtual void Skill(SkillType _SkillType);



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
	void SetCurDuration(float _CurDuration) {
		CurDuration = _CurDuration;
	}
	float GetCurDuration() const
	{
		return CurDuration;
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
	SkillType GetCurSkillType() const {
		return CurSkillType;
	}
	void SetCurSKillType(SkillType _SkillType) {
		CurSkillType = _SkillType;
	}
	CampType GetCurCamp() 
	{
		return CurCamp;
	}
	float GetSpeed() 
	{
		return Speed;
	};
	void SetSpeed(float _Speed)
	{
		Speed = _Speed;
	};

	class APokemon* GetTargetPokemon() const
	{
		return TargetPokemon;
	};

	void SetTargetPokemon(class APokemon* _TargetPokemon) {
		TargetPokemon = _TargetPokemon;
	}


protected:
	class USpriteRenderer* SpriteRenderer;
	class APokemon* TargetPokemon;

	DIR CurDir = DIR::Down;
	float CurDuration;
	FVector2D StartLocation;
	FVector2D TargetLocation;

	SkillType CurSkillType = SkillType::NormalAttack;

	CampType CurCamp;

	float Speed = 1.0f;

	virtual void AnimationSetting()=0;

private:

};

