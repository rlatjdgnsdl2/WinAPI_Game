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

	void Idle();
	void MoveStart();
	void Move(float _DeltaTime);

	void Skill();
	void Hurt();
	void Die(float _DeltaTime);


	virtual void LevelUp() {}
	virtual bool IsLevelUp() { return false; }
	virtual bool GainExp(int _Exp) { return false; }

	void SetDir(DIR _Dir) {
		Dir = _Dir;
	}
	DIR GetDir() const {
		return Dir;
	}
	void SetCamp(CampType _Camp) {
		Camp = _Camp;
	}
	CampType GetCamp() const {
		return Camp;
	}
	void SetTile(const FIntPoint& _CurTileIndex) {
		SetActorLocation(_CurTileIndex * 72.0f);
	}
	const FIntPoint GetTile() {
		return ((GetActorLocation().ConvertToPoint()) / 72);
	}

	//	이동관련
	const FVector2D GetTargetLocation() const {
		return TargetLocation;
	}
	const FIntPoint GetTargetTile() {
		return ((TargetLocation.ConvertToPoint()) / 72);
	}
	void SetTargetLocation(const FVector2D& _TargetLocation) {
		TargetLocation = _TargetLocation;
		StartLocation = GetActorLocation();
	}
	void SetTargetTile(const FIntPoint& _TargetTileIndex) {
		TargetLocation = _TargetTileIndex * 72.0f;
		StartLocation = GetActorLocation();
	}
	void ResetCurDuration() {
		CurDuration = 0.0f;
	}
	void SetMoveSpeed(float _MoveSpeed) {
		MoveSpeed = _MoveSpeed;
	}
	void SetWalk() {
		MoveSpeed = 2.0f;
	}
	void SetRun() {
		MoveSpeed = 4.0f;
	}
	float GetMoveSpeed() const {
		return MoveSpeed;
	}




	//	전투관련
	void SetSkill(SkillType _Skill) {
		CurSkill = _Skill;
	}
	SkillType GetSkill() const {
		return CurSkill;
	}
	void SetTargetPokemon(class APokemon* _TargetPokemon) {
		TargetPokemon = _TargetPokemon;
	}
	void PushTargetablePokemon(class APokemon* _TargetablePokemon) {
		TargetablePokemons.push_back(_TargetablePokemon);
	}
	void ClearTargetablePokemon() {
		TargetablePokemons.clear();
	}
	class APokemon* GetTargetPokemon() const {
		return TargetPokemon;
	}
	std::vector<class APokemon*>& GetTargetablePokemons() {
		return TargetablePokemons;
	}
	void ResetTargetablePokemon() {
		TargetablePokemons.clear();
	}

	//	전투
	void StartAttack();
	void EndAttack();
	bool IsAttack() const {
		return IsAttackVal;
	}

	void NormalAttack();
	void SpecialAttack();
	void PlayHurtAnim();

	const std::list<std::string>& GetSkillList() {
		return SpecialSkillList;
	}
	std::string GetCurSpecialSkillName() {
		return CurSpecialSkillName;
	}
	void SetCurSpecialSkillName(std::string_view _SpecialSkillName) {
		CurSpecialSkillName = _SpecialSkillName;
	}

	int GetCurHP() const {
		return Ability.CurHP;
	}
	int GetMaxHP() const {
		return Ability.MaxHP;
	}
	int GetATK() const {
		return Ability.CurATK;
	}
	int GetSTK() const {
		return Ability.CurSTK;
	}
	int GetDEF() const {
		return Ability.CurDEF;
	}
	int GetSPD() const {
		return Ability.CurSPD;
	}
	void InitAbility(const PokemonInfo& PokemonInfo, int _Level) {
		Ability.InitAbility(PokemonInfo, _Level);
	}

	void SetDamage(int _Damage) {
		Ability.CurHP -= _Damage;
		if (Ability.CurHP < 0) {
			Ability.CurHP = 0;
		}
	}
	void SetHeal(int _Heal) {
		Ability.CurHP += _Heal;
		if (Ability.CurHP > Ability.MaxHP) {
			Ability.CurHP = Ability.MaxHP;
		}
	}

	bool IsDie() {
		return Ability.CurHP <= 0;
	}
	int GetLevel() const {
		return Level;
	}







protected:
	DIR Dir = DIR::Down;
	CampType Camp = CampType::None;
	float MoveSpeed = 2.0f;
	int Level{};

	class USpriteRenderer* SpriteRenderer = nullptr;

	//	이동관련
	float CurDuration = 0.0f;
	float DeadDuration = 0.0f;
	FVector2D StartLocation = FVector2D::ZERO;
	FVector2D TargetLocation = FVector2D::ZERO;

	//	전투관련
	SkillType CurSkill = SkillType::None;
	std::vector<class APokemon*> TargetablePokemons;
	class APokemon* TargetPokemon = nullptr;

	//	스킬관련
	class ASpecialSkill* SpecialSkill = nullptr;
	std::list<std::string> SpecialSkillList;
	std::string CurSpecialSkillName = "";

	//	능력치관련
	PokemonInfo PokemonInfo;
	PokemonAbility Ability;

	bool IsAttackVal{};
	bool IsHurtVal{};
private:
	void SetAnim();








};

