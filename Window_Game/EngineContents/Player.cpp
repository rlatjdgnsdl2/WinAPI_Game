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

void APlayer::SetAnim()
{
	APokemon::SetAnim();
	float ShootFrame = 0.5f / CurAnimInfo.ShootAnimCount;
	SpriteRenderer->CreateAnimation("ShootAnim_2", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 0, CurAnimInfo.ShootAnimCount * 1 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_3", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 1, CurAnimInfo.ShootAnimCount * 2 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_6", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 2, CurAnimInfo.ShootAnimCount * 3 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_9", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 3, CurAnimInfo.ShootAnimCount * 4 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_8", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 4, CurAnimInfo.ShootAnimCount * 5 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_7", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 5, CurAnimInfo.ShootAnimCount * 6 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_4", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 6, CurAnimInfo.ShootAnimCount * 7 - 1, ShootFrame,false);
	SpriteRenderer->CreateAnimation("ShootAnim_1", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 7, CurAnimInfo.ShootAnimCount * 8 - 1, ShootFrame,false);

}











