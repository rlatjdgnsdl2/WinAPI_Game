#pragma once
#include "Pokemon.h"

// Ό³Έν :
class APartner:public APokemon
{
public:
	// constrcuter destructer
	APartner();
	virtual ~APartner();

	// delete Function
	APartner(const APartner& _Other) = delete;
	APartner(APartner&& _Other) noexcept = delete;
	APartner& operator=(const APartner& _Other) = delete;
	APartner& operator=(APartner&& _Other) noexcept = delete;


	virtual void BeginPlay() override;

	virtual void LevelChangeStart()override;

	virtual void LevelChangeEnd()override;

	virtual void SetPokemon(std::string_view _PokemonName) override;

	virtual void LevelUp() override {
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
	virtual bool IsLevelUp() override {
		if (Exp >= MaxExp) {
			return true;
		}
		return false;
	}
	virtual bool GainExp(int _Exp) override {
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

