#include "PreCompile.h"
#include "Player.h"
#include "GameDataManager.h"
#include <EngineCore/SpriteRenderer.h>




APlayer::APlayer()
{
	SetCamp(CampType::Player);
}



APlayer::~APlayer()
{

}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
	SetName(UGameDataManager::GetInst().GetSelectPlayer());
	SetPokemon(GetName());
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
	PlayerData PlayerData = UGameDataManager::GetInst().GetPlayerData(GetName());
	Level = PlayerData.Level;
	MaxExp = Level * 100;
	InitAbility(PokemonInfo, Level+10);
}


void APlayer::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	UGameDataManager::GetInst().SetPlayerData(GetName(), Level);
}

void APlayer::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	PlayerData PlayerData = UGameDataManager::GetInst().GetPlayerData(_PokemonName);
	Level = PlayerData.Level;
	MaxExp = Level * 100;
	InitAbility(PokemonInfo, PlayerData.Level+10);
}

















