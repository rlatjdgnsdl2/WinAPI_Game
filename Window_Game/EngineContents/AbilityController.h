#pragma once
#include <EngineCore/ActorComponent.h>

//	설명:
class UAbilityController :public UActorComponent
{
public:
	friend class APokemon;
	//	constrcuter, destructer
	UAbilityController();
	virtual ~UAbilityController();

	//	delete Function
	UAbilityController(const UAbilityController& _Other) = delete;
	UAbilityController(UAbilityController&& _Other) noexcept = delete;
	UAbilityController& operator=(const UAbilityController& _Other) = delete;
	UAbilityController& operator=(UAbilityController&& _Other) noexcept = delete;

	void InitCurStatus(const PokemonInfo& _PokemonInfo) {
		// 고쳐야함
		CurStatus = _PokemonInfo;
		CurStatus.CurHp = CurStatus.MaxHp;
		CurStatus.MaxEXP = CurStatus.Level * 100;
	}
	int GetSpeed() const{
		return CurStatus.SPD;
	}
	void LevelUp() {
		CurStatus.Level += 1;
		CurStatus.EXP = 0;
	}
	void SetDamage(int _Atk) {
		CurStatus.CurHp -= _Atk;
		if (CurStatus.CurHp < 0) {
			CurStatus.CurHp = 0;
		}
	}
	void Recover(int _Recover) {
		CurStatus.CurHp += _Recover;
		if (CurStatus.CurHp > CurStatus.MaxHp) {
			CurStatus.CurHp = CurStatus.MaxHp;
		}
	}
	void SetExp(int _EXP) {
		CurStatus.EXP += _EXP;
		if (CurStatus.EXP > CurStatus.MaxEXP) {
			LevelUp();
			CurStatus.MaxEXP = CurStatus.Level * 100;
		}
	}
	int DropExp() {
		return CurStatus.Level * 2;
	}
	bool IsDie() {
		return CurStatus.CurHp == 0;
	}
	int GetATK() {
		return CurStatus.ATK;
	}
protected:

private:
	PokemonInfo CurStatus;
	

};

