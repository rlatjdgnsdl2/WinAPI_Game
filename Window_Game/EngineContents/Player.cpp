#include "PreCompile.h"
#include "Player.h"
#include "GameDataManager.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>

#include "AbilityController.h"





APlayer::APlayer()
{

}



APlayer::~APlayer()
{

}


void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineDebug::CoreOutPutString(std::to_string(1 / _DeltaTime));
}

void APlayer::SetPokemon(std::string_view _PokemonName)
{
	APokemon::SetPokemon(_PokemonName);
	AbilityController->InitCurAbility(UGameDataManager::GetInst().GetPlayerAbility(GetName()));
}

//void APlayer::EndAttack()
//{
//	if (TargetPokemon != nullptr) {
//		TargetPokemon->GetCurAbility().SetDamage(AbilityController.GetATK());
//		bool IsDie = TargetPokemon->GetCurAbility().IsDie();
//		if (IsDie) {
//			AbilityController.SetExp(TargetPokemon->GetCurAbility().DropExp());
//		}
//	}
//	IsAttackValue = false;
//}










