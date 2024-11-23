#pragma once
#include "Pokemon.h"




//	Ό³Έν:
class APlayer :public APokemon
{
public:

	//	constrcuter, destructer
	APlayer();
	virtual ~APlayer();

	//	delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	virtual void BeginPlay() override;

	virtual void SetPokemon(std::string_view _PokemonName) override;

	void LevelUp() {
		Level++;
		Ability.MaxHP += 2;
		Ability.CurHP += 2;
		Ability.ATK += 2;
		Ability.CurATK += 2;
		Ability.STK += 2;
		Ability.CurSTK += 2;
		Ability.DEF += 2;
		Ability.CurDEF += 2;
		Ability.SPD += 2;
		Ability.CurSPD += 2;
		MaxExp = Level * 100;
		Exp = 0;
	};
	bool IsLevelUp() {
		if (Exp >= MaxExp) {
			return true;
		}
		return false;
	}
	bool GainExp(int _Exp) {
		Exp += _Exp;
		if (IsLevelUp()) {
			LevelUp();
			return true;
		}
		return false;
	}
protected:

private:
	int MaxExp{};
	int Exp{};
};

