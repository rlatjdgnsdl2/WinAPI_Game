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


void APlayer::BeginPlay()
{
	Super::BeginPlay();
	{
		USpriteRenderer* UIRenderer = CreateDefaultSubObject<USpriteRenderer>();
		UIRenderer->SetSprite("DungeonFont_LV.png", 0);
		UIRenderer->SetSpriteScale();
		UIRenderer->SetOrder(ERenderOrder::UI);
		UIRenderer->SetCameraEffect(false);
		UIRenderer->SetComponentLocation({ 18 + 24 * 3,18 });
		UIRenderers.insert({ "LV", UIRenderer });
	}
	{
		USpriteRenderer* UIRenderer = CreateDefaultSubObject<USpriteRenderer>();
		UIRenderer->SetSprite("DungeonFont_0.png", 0);
		UIRenderer->SetSpriteScale();
		UIRenderer->SetOrder(ERenderOrder::UI);
		UIRenderer->SetCameraEffect(false);
		UIRenderer->SetComponentLocation({ 18 + 24 * 4,18 });
		UIRenderers.insert({ "LvN", UIRenderer });
	}
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetPokemon("Mudkip");
	UIRenderers["LvN"]->SetSprite(std::format("DungeonFont_{}.png", GetCurAbility()->GetLevel()), 0);

}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	//UEngineDebug::CoreOutPutString(std::to_string(1 / _DeltaTime));
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










