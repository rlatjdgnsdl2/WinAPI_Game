#pragma once
#include "Pokemon.h"


//	Ό³Έν:
class APartner :public APokemon
{
public:
	//	constrcuter, destructer
	APartner();
	virtual ~APartner();

	virtual void SetPokemon(std::string_view _PokemonName);

	//	delete Function
	APartner(const APartner& _Other) = delete;
	APartner(APartner&& _Other) noexcept = delete;
	APartner& operator=(const APartner& _Other) = delete;
	APartner& operator=(APartner&& _Other) noexcept = delete;

	virtual void SetCamp(CampType _Camp) {
		Camp = _Camp;
	}
	virtual CampType GetCamp() {
		return Camp;
	}


protected:

private:
	CampType Camp = CampType::Player;

};

