#include "PreCompile.h"
#include "Player.h"
#include "GameDataManager.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>





APlayer::APlayer()
{

}



APlayer::~APlayer()
{

}


void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineDebug::CoreOutPutString(std::to_string(1/_DeltaTime));

}

void APlayer::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	CurCamp = CampType::Player;
	CurPokemonAbility = UGameDataManager::GetInst().GetPlayerAbility(CurPokemonName);
}










