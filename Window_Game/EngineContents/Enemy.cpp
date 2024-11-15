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
	CurAbility.SetCurStatus(UGameDataManager::GetInst().GetPokemonAbility(GetName()));

}
