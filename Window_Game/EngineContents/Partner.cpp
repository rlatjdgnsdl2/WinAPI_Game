#include "PreCompile.h"
#include "Partner.h"
#include "GameDataManager.h"

APartner::APartner()
{
	SetCamp(CampType::Player);
}

APartner::~APartner()
{
}

void APartner::BeginPlay()
{
	Super::BeginPlay();
	SetName(UGameDataManager::GetInst().GetSelectPartner());
	SetPokemon(GetName());
}

void APartner::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetName(UGameDataManager::GetInst().GetSelectPartner());
	PlayerData PlayerData = UGameDataManager::GetInst().GetPlayerData(GetName());
	Level = PlayerData.Level;
	MaxExp = Level * 100;
	InitAbility(PokemonInfo, PlayerData.Level + 10);
	
}


void APartner::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	UGameDataManager::GetInst().SetPlayerData(GetName(), Level);
}

void APartner::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	PlayerData PlayerData = UGameDataManager::GetInst().GetPlayerData(_PokemonName);
	Level = PlayerData.Level;
	MaxExp = Level * 100;
	InitAbility(PokemonInfo, PlayerData.Level + 10);
}

