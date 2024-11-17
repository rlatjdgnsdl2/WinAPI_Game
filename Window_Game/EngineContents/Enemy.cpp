#include "PreCompile.h"
#include "Enemy.h"

#include "GameDataManager.h"

#include "AbilityController.h"


AEnemy::AEnemy() 
{

}
AEnemy::~AEnemy() 
{

}

void AEnemy::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	AbilityController->InitCurStatus(UGameDataManager::GetInst().GetPokemonAbility(GetName()));

}
