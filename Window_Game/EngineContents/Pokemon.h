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
	virtual void SetAnim();
	void Idle();
	void Move(float _DeltaTime);
	virtual void Skill();
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
	const FIntPoint GetTile() {
		return ((GetActorLocation().ConvertToPoint()) / 72);
	};

	//	이동관련
	const FVector2D GetTargetLocation() const;
	const FIntPoint GetTargetTile();
	void SetTargetLocation(const FVector2D& _TargetLocation);
	void SetTargetTile(const FIntPoint& _TargetTileIndex);
	void ResetCurDuration();


	//	전투관련
	void SetSkill(SkillType _Skill);
	SkillType GetSkill() const;
	void SetTargetPokemon(class APokemon* _TargetPokemon);
	void PushTargetablePokemon(class APokemon* _TargetablePokemon);
	void ClearTargetablePokemon();
	class APokemon* GetTargetPokemon() const;
	std::vector<class APokemon*>& GetTargetablePokemons();

	virtual void SetCamp(CampType _Camp) = 0;
	virtual CampType GetCamp() = 0;

	//	전투
	void NormalAttack();
	void SpecialAttack();
	void ReadyAttack();
	virtual void EndAttack();
	bool IsAttack();
	void PlayHurtAnim();

	class UAbilityController* GetCurAbility() {
		return AbilityController;
	}
	
	const std::list<std::string>& GetSkillList() {
		return SkillList;
	}
	std::string GetCurSpecialSkillName() {
		return CurSpecialSKillName;
	}
	void SetCurSpecialSkillName(std::string_view _SpecialSkillName) {
		CurSpecialSKillName = _SpecialSkillName;
	}



protected:
	DIR Dir;
	class USpriteRenderer* SpriteRenderer;
	AnimInfo CurAnimInfo;

	//	이동관련
	float CurDuration;
	FVector2D StartLocation;
	FVector2D TargetLocation;

	//	전투관련
	SkillType CurSkill;
	std::vector<class APokemon*> TargetablePokemons;
	class APokemon* TargetPokemon;
	std::list<std::string> SkillList;
	class ASpecialSkill* SpecialSkill;
	class UAbilityController* AbilityController;

	std::string CurSpecialSKillName="";

	bool IsAttackValue;
	bool IsHurtValue;

	int CurLevel;
	int CurMaxHp;
	int CurHp;
	int CurATK;
	int CurSPD;
private:








};

