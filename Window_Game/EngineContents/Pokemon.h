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
	
	virtual void SetPokemon(std::string_view _PokemonName);
	virtual void Idle();
	virtual void Move(float _DeltaTime);
	virtual void Skill(SkillType _SkillType);
	virtual void Hurt();



	DIR GetCurDir() const { return CurDir; }
	void SetCurDir(DIR _dir) { CurDir = _dir; }

	void SetCurDuration(float _CurDuration) { CurDuration = _CurDuration; }

	FVector2D GetStartLocation() const	{ return StartLocation; }
	void SetStartLocation(FVector2D _StartLocation) { StartLocation = _StartLocation; }

	FVector2D GetTargetLocation() const { return TargetLocation; }
	void SetTargetLocation(FVector2D _TargetLocation) { TargetLocation = _TargetLocation; }

	SkillType GetCurSkillType() const { return CurSkillType; }
	void SetCurSkillType(SkillType _SkillType) { CurSkillType = _SkillType; }

	CampType GetCurCamp() const { return CurCamp; }
	void SetCurCamp(CampType _CampType) { CurCamp = _CampType; }
	
	class APokemon* GetTargetPokemon() const { return TargetPokemon; }
	void SetTargetPokemon(class APokemon* _TargetPokemon) { TargetPokemon = _TargetPokemon; }

	PokemonAbility GetPokemonStat() const { return CurPokemonAbility; }
	void SetPokemonStat(PokemonAbility _PokemonStat){ CurPokemonAbility = _PokemonStat; }



	virtual void AnimationSetting();

	
	


protected:
	std::string CurPokemonName;
	class USpriteRenderer* SpriteRenderer;
	PokemonAnimaionInfo CurPokemonAnimationInfo;

	//	기본
	CampType CurCamp;
	DIR CurDir;

	//	이동관련
	float CurDuration;
	FVector2D StartLocation;
	FVector2D TargetLocation;

	//	전투관련
	class APokemon* TargetPokemon;
	SkillType CurSkillType;

	PokemonAbility CurPokemonAbility;


private:


};

