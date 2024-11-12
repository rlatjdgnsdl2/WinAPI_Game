#include "PreCompile.h"
#include "Partner.h"

#include "GameDataManager.h"



APartner::APartner() 
{

}
APartner::~APartner() 
{

}

void APartner::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	CurCamp = CampType::Player;
	CurPokemonAbility = UGameDataManager::GetInst().GetPlayerAbility(CurPokemonName);
}
