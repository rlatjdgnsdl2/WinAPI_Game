#pragma once
#include <EngineCore/Actor.h>





//	Ό³Έν:
class APokemon :public AActor
{
public:

	friend class TurnManager;
	//	constrcuter, destructer
	APokemon();
	APokemon(std::string_view _CurPokemonName);
	virtual ~APokemon();

	//	delete Function
	APokemon(const APokemon& _Other) = delete;
	APokemon(APokemon&& _Other) noexcept = delete;
	APokemon& operator=(const APokemon& _Other) = delete;
	APokemon& operator=(APokemon&& _Other) noexcept = delete;

	virtual void LevelChangeStart()override;

	virtual void Idle();
	virtual void Move(float _DeltaTime);
	virtual void Skill(SkillType _SkillType);



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

	virtual void AnimationSetting();
	




protected:
	class USpriteRenderer* SpriteRenderer;
	class APokemon* TargetPokemon;

	float CurDuration;
	CampType CurCamp;
	DIR CurDir = DIR::Down;
	FVector2D StartLocation;
	FVector2D TargetLocation;
	SkillType CurSkillType = SkillType::NormalAttack;

	PokemonInfo CurPokemonInfo;
	PokemonData CurPokemonData;

private:


};

