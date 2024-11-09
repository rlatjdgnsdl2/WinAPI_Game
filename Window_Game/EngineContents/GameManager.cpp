#include "PreCompile.h"
#include "GameManager.h"

GameManager::GameManager()
{
	PlayerAbility = { Pokemon_Type::Fire,50.0f,15.0f,15.0f,15.0f,15.0f ,1.0f };
	BasicAbilities.insert({ "TempPokemon",{ Pokemon_Type::Fire,20.0f,0.0f,0.0f,0.0f,0.0f ,1.0f} });
}

GameManager::~GameManager()
{

}

