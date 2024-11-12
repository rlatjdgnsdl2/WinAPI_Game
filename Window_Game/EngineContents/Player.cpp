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
	UEngineDebug::CoreOutPutString("Fps :"+std::to_string(1/_DeltaTime));
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetPokemon("Mudkip");
}

void APlayer::SetPokemon(std::string_view _PokemonName)
{
	if (SpriteRenderer == nullptr) {
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	}
	CurPokemonName = _PokemonName;
	SpriteRenderer->SetSprite(CurPokemonName + "_Idle.png");
	SpriteRenderer->SetSpriteScale();
	CurPokemonAnimationInfo = UGameDataManager::GetInst().GetPokemonAnimationInfo(CurPokemonName);
	AnimationSetting();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);

	TargetPokemon = nullptr;
	CurDuration = 0.0f;
	CurDir = DIR::Down;
	CurCamp = CampType::Player;
	SkillType CurSkillType = SkillType::NormalAttack;
	CurPokemonAbility = UGameDataManager::GetInst().GetPlayerAbility(CurPokemonName);
}









