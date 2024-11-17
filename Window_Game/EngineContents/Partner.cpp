#include "PreCompile.h"
#include "Partner.h"
#include "GameDataManager.h"
#include "AbilityController.h"



APartner::APartner() 
{

}
APartner::~APartner() 
{

}

void APartner::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	AbilityController->InitCurAbility(UGameDataManager::GetInst().GetPlayerAbility(GetName()));
}
