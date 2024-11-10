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
	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("X : " + std::to_string(GetActorLocation().X));
	UEngineDebug::CoreOutPutString("Y : " + std::to_string(GetActorLocation().Y));
}

void APlayer::LevelChangeStart()
{
	APokemon::LevelChangeStart();
	CurCamp = CampType::Player;
}









