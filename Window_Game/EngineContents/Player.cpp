#include "PreCompile.h"
#include "Player.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>


APlayer::APlayer()
{
	
}

APlayer::APlayer(std::string_view _CurPokemonName):APokemon(_CurPokemonName)
{

}

APlayer::~APlayer()
{

}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}

void APlayer::LevelChangeStart()
{
	APokemon::LevelChangeStart();
	CurCamp = CampType::Player;
}









