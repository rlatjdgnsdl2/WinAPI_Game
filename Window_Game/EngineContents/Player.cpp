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
	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("디버그 모드 U, 카메라 I,J,K,L");
}

void APlayer::LevelChangeStart()
{
	APokemon::LevelChangeStart();
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(true);
	CurCamp = CampType::Player;
}









