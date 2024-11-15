#include "PreCompile.h"
#include "Enemy.h"

#include "GameDataManager.h"



AEnemy::AEnemy() 
{

}
AEnemy::~AEnemy() 
{

}

void AEnemy::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	SetCamp(CampType::Enemy);
	SetCurAbility(UGameDataManager::GetInst().GetPokemonAbility(GetName()));

}
