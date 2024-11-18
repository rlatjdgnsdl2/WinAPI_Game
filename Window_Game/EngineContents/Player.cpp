#include "PreCompile.h"
#include "Player.h"
#include "GameDataManager.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>

#include "AbilityController.h"
#include "GameDataManager.h"





APlayer::APlayer()
{

}



APlayer::~APlayer()
{

}


void APlayer::BeginPlay()
{
	Super::BeginPlay();
	SetName(UGameDataManager::GetInst().GetSelectPlayer());
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetPokemon(GetName());
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void APlayer::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	AbilityController->InitCurAbility(UGameDataManager::GetInst().GetPlayerAbility(GetName()));
}











