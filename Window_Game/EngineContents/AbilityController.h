#pragma once
#include <EngineCore/ActorComponent.h>

//	설명:
class UAbilityController :public UActorComponent
{
public:
	//	constrcuter, destructer
	UAbilityController();
	virtual ~UAbilityController();

	//	delete Function
	UAbilityController(const UAbilityController& _Other) = delete;
	UAbilityController(UAbilityController&& _Other) noexcept = delete;
	UAbilityController& operator=(const UAbilityController& _Other) = delete;
	UAbilityController& operator=(UAbilityController&& _Other) noexcept = delete;

	//	나중에 플레이어 데이터로 변경
	void InitCurAbility(const PokemonInfo& _PokemonInfo) {
		CurLevel = _PokemonInfo.Level;
		MaxHp = _PokemonInfo.MaxHp;
		CurHp = MaxHp;
		ATK = _PokemonInfo.ATK;
		CurSPD = _PokemonInfo.SPD;
		MaxExp = CurLevel * 100;
		CurExp = 0;
	}
	void LevelUp() {
		CurLevel++;
		MaxHp += 2;
		CurHp +=2;
		ATK += 2;
		MaxExp = CurLevel * 100;
		CurExp = 0;
	}
	void SetDamage(int _Damage) {
		CurHp -= _Damage;
		if (CurHp <= 0) {
			CurHp = 0;
		}	
	}
	void SetHeal(int _Heal) {
		CurHp += _Heal;
	}
	void SetExp(int _Exp) {
		CurExp += _Exp;
		if (CurExp >= MaxExp) {
			LevelUp();
		}
	}
	int GetATK() const {
		return ATK;
	}
	int GetSPD() const {
		return CurSPD;
	}
	bool IsDie() const {
		return CurHp <= 0;
	}
	int GetLevel() const {
		return CurLevel;
	}
	int GetCurHP() const {
		return CurHp;
	}
	int GetMaxHP() const {
		return MaxHp;
	}
protected:

private:
	int CurLevel{};
	int MaxHp{};
	int CurHp{};
	int ATK{};
	int DEF{};
	int SATK{};
	int SDEF{};
	int CurSPD{};

	int MaxExp{};
	int CurExp{};
	int Hungry{};


};

