#pragma once
#include <EngineCore/Actor.h>

//	설명:
class APokemon :public AActor
{
public:


	APokemon();
	virtual ~APokemon();
	APokemon(const APokemon& _Other) = delete;
	APokemon(APokemon&& _Other) noexcept = delete;
	APokemon& operator=(const APokemon& _Other) = delete;
	APokemon& operator=(APokemon&& _Other) noexcept = delete;

	virtual void SetPokemon(std::string_view _PokemonName);
	void AnimSet();
	void Idle();
	void Move(float _DeltaTime);
	void Skill(SkillType _Skill);
	void Hurt();

	void SetDir(DIR _Dir) {
		Dir = _Dir;
	}
	DIR GetDir() {
		return Dir;
	}
	void SetTile(const FIntPoint& _CurTileIndex) {
		SetActorLocation(_CurTileIndex * 72.0f);
	};
	const FIntPoint& GetTile() {
		return ((GetActorLocation().ConvertToPoint()) / 72);
	};

	//	이동관련
	const FVector2D& GetTargetLocation() const;
	const FIntPoint& GetTargetTile();
	void SetTargetLocation(const FVector2D& _TargetLocation);
	void SetTargetTile(const FIntPoint& _TargetTileIndex);
	void ResetCurDuration();


	virtual void SetCamp(CampType _Camp) = 0;
	virtual CampType GetCamp() = 0;

	//	전투
	void NormalAttack();
	void SpecialAttack();
	void StartAttack();
	virtual void EndAttack();
	bool IsAttack();
	void PlayHurtAnim();

	class UAbilityController* GetCurAbility() {
		return AbilityController;
	}

	class USkillController* GetSkillController() {
		return SkillController;
	}

protected:
	class USpriteRenderer* SpriteRenderer;

	//	이동관련
	float CurDuration;
	FVector2D StartLocation;
	FVector2D TargetLocation;



	class UAbilityController* AbilityController;
	class USkillController* SkillController;

	
	DIR Dir;
	bool IsAttackValue;
	bool IsHurtValue;
private:








};

