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
	virtual void Tick(float _DeltaTime)override;


	void LevelChangeStart() override;
	virtual void SetPokemon(std::string_view _PokemonName)override;

protected:

private:
	
};

