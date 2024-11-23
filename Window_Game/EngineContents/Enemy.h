#pragma once
#include "Pokemon.h"

//	Ό³Έν:
class AEnemy :public APokemon
{
public:
	
	//	constrcuter, destructer
	AEnemy(std::string_view _PokemonName,int _Level);
	virtual ~AEnemy();

	//	delete Function
	AEnemy(const AEnemy& _Other) = delete;
	AEnemy(AEnemy&& _Other) noexcept = delete;
	AEnemy& operator=(const AEnemy& _Other) = delete;
	AEnemy& operator=(AEnemy&& _Other) noexcept = delete;

	virtual void BeginPlay() override;


	virtual void SetPokemon(std::string_view _PokemonName) override;
	void SetLevel(int _Level) {
		Level = _Level;
	}
	int GetLevel() const {
		return Level;
	}


protected:

private:
};

