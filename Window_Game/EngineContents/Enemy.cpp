#include "PreCompile.h"
#include "Enemy.h"

#include "GameDataManager.h"





AEnemy::AEnemy(std::string_view _PokemonName, int _Level)
{
	SetCamp(CampType::Enemy);
	Level = _Level;
	SetName(_PokemonName);
}
AEnemy::~AEnemy() 
{

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	SetPokemon(GetName());
}

void AEnemy::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	InitAbility(PokemonInfo, Level);
}
