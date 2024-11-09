#pragma once
#include <EngineCore/Actor.h>





//	설명:
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


	//GetSet	friend class 질문

	DIR GetDir() const { return CurDir; }
	void SetDir(DIR _dir) { CurDir = _dir; }

	void SetCurDuration(float _CurDuration) { CurDuration = _CurDuration; }

	FVector2D GetStartLocation() const	{ return StartLocation; }
	void SetStartLocation(FVector2D _StartLocation) { StartLocation = _StartLocation; }

	FVector2D GetTargetLocation() const { return TargetLocation; }
	void SetTargetLocation(FVector2D _TargetLocation) { TargetLocation = _TargetLocation; }

	SkillType GetCurSkillType() const { return CurSkillType; }
	void SetCurSkillType(SkillType _SkillType) { CurSkillType = _SkillType; }

	CampType GetCurCamp() const { return CurCamp; }
	
	class APokemon* GetTargetPokemon() const { return TargetPokemon; }
	void SetTargetPokemon(class APokemon* _TargetPokemon) { TargetPokemon = _TargetPokemon; }
	



protected:
	class USpriteRenderer* SpriteRenderer;
	class APokemon* TargetPokemon;

	CampType CurCamp;
	float CurDuration;
	DIR CurDir = DIR::Down;
	FVector2D StartLocation;
	FVector2D TargetLocation;
	SkillType CurSkillType = SkillType::NormalAttack;
	
	virtual void AnimationSetting() = 0;

private:

};

