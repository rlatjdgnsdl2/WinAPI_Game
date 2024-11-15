#pragma once

//	Ό³Έν:
class PokemonAbility 
{
public:
	//	constrcuter, destructer
	PokemonAbility();
	virtual ~PokemonAbility();

	//	delete Function
	PokemonAbility(const PokemonAbility& _Other) = delete;
	PokemonAbility(PokemonAbility&& _Other) noexcept = delete;
	PokemonAbility& operator=(const PokemonAbility& _Other) = delete;
	PokemonAbility& operator=(PokemonAbility&& _Other) noexcept = delete;

	void SetCurStatus(const PokemonInfo& _PokemonInfo) {
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

