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
	virtual void Skill();
	virtual void Hurt();

	DIR GetCurDir() const {
		return CurDir;
	}
	void SetCurDir(DIR _dir) {
		CurDir = _dir;
	}

	void ResetCurDuration() {
		CurDuration = 0.0f;
	}
	//	StartLocation
	FVector2D GetStartLocation() const {
		return StartLocation;
	}
	FIntPoint GetStartTile() {
		FIntPoint CurStartTileIndex = (StartLocation.ConvertToPoint()) / 72;
		return CurStartTileIndex;
	}
	void SetStartLocation(const FVector2D& _StartLocation) {
		StartLocation = _StartLocation;
	}
	void SetStartLocation(const FIntPoint& _StartTileIndex) {
		StartLocation = _StartTileIndex * 72.0f;
	}
	//	Target
	FVector2D GetTargetLocation() const {
		return TargetLocation;
	}
	FIntPoint GetTargetTile() {
		FIntPoint CurTargetTileIndex = (TargetLocation.ConvertToPoint()) / 72;
		return CurTargetTileIndex;
	}
	void SetTargetLocation(const FVector2D& _TargetLocation) {
		TargetLocation = _TargetLocation;
	}
	void SetTargetLocation(const FIntPoint& _TargetTileIndex) {
		TargetLocation = _TargetTileIndex * 72.0f;
	}
	//	현재
	FIntPoint GetCurTile() {
		FIntPoint CurTileIndex = (GetActorLocation().ConvertToPoint()) / 72;
		return CurTileIndex;
	}
	void SetCurTileIndex(FIntPoint _TileIndex) {
		SetActorLocation(_TileIndex * 72.0f);
	}


	SkillType GetCurSkillType() const {
		return CurSkillType; 
	}
	void SetCurSkillType(SkillType _SkillType) { 
		CurSkillType = _SkillType; 
	}

	CampType GetCurCamp() const { 
		return CurCamp; 
	}
	void SetCurCamp(CampType _CampType) { 
		CurCamp = _CampType; 
	}

	class APokemon* GetTargetPokemon() const { 
		return TargetPokemon; 
	}
	void SetTargetPokemon(class APokemon* _TargetPokemon) { 
		TargetPokemon = _TargetPokemon; 
	}

	PokemonAbility GetPokemonStat() const { 
		return CurPokemonAbility; 
	}
	void SetPokemonAbility(const PokemonAbility& _PokemonAbility) { CurPokemonAbility = _PokemonAbility; }

	void StartAttack();
	void EndAttack();
	bool IsAttack() {
		return IsAttackValue;
	};
	void PlayHurtAnim();
	virtual void AnimationSetting();


protected:
	class USpriteRenderer* SpriteRenderer;

	bool IsAttackValue;
	bool IsHurtValue;

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



	std::string CurPokemonName;
	PokemonAnimaionInfo CurPokemonAnimationInfo;
	PokemonAbility CurPokemonAbility;
private:


};

