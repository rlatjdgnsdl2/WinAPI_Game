#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>
#include "GameDataManager.h"




APokemon::APokemon()
{
}
APokemon::APokemon(std::string_view _CurPokemonName)
{
	CurPokemonInfo = UGameDataManager::GetInst().GetPokemonInfo(_CurPokemonName);
	//CurPokemonData = UGameDataManager::GetInst().GetPokemonData(_CurPokemonName);
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite(CurPokemonInfo.PokemonName + "_Idle.png");
	SpriteRenderer->SetSpriteScale();
	AnimationSetting();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	
}
APokemon::~APokemon()
{

}

void APokemon::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void APokemon::Idle()
{
	SpriteRenderer->ChangeAnimation("IdleAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration *2.0f);	//나중에 스피드 설정
	SetActorLocation(NewLocation);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::Skill(SkillType _SkillType)
{
	switch (_SkillType)
	{
	case SkillType::NormalAttack:
		SpriteRenderer->ChangeAnimation("AttackAnim_" + std::to_string((int)CurDir));
		SpriteRenderer->SetSpriteScale();
		break;
	case SkillType::SpecialAttack:
		break;
	case SkillType::UseItem:
		break;
	default:
		break;
	}

}

void APokemon::AnimationSetting()
{
	//	Idle
	std::vector<int> IdleIndex_2(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_3(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_6(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_9(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_8(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_7(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_4(CurPokemonInfo.IdleAnimCount);
	std::vector<int> IdleIndex_1(CurPokemonInfo.IdleAnimCount);
	std::vector<std::vector<int>> IdleIndex = { IdleIndex_2,IdleIndex_3,IdleIndex_6,IdleIndex_9,IdleIndex_8,IdleIndex_7,IdleIndex_4,IdleIndex_1 };
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < CurPokemonInfo.IdleAnimCount; x++)
		{
			IdleIndex[y][x] = x + y * CurPokemonInfo.IdleAnimCount;
		}
	}
	std::vector<float> IdleFrame(CurPokemonInfo.IdleAnimCount, 0.2f);
	IdleFrame[0] = 0.2f * (11 - CurPokemonInfo.IdleAnimCount);
	SpriteRenderer->CreateAnimation("IdleAnim_2", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[0], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_3", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[1], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_6", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[2], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_9", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[3], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_8", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[4], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_7", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[5], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_4", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[6], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_1", CurPokemonInfo.PokemonName + "_Idle.png", IdleIndex[7], IdleFrame);

	//	Walk
	float WalkFrame = 0.5f / CurPokemonInfo.WalkAnimCount;
	SpriteRenderer->CreateAnimation("WalkAnim_2", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 0, CurPokemonInfo.WalkAnimCount * 1 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_3", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 1, CurPokemonInfo.WalkAnimCount * 2 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_6", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 2, CurPokemonInfo.WalkAnimCount * 3 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_9", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 3, CurPokemonInfo.WalkAnimCount * 4 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_8", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 4, CurPokemonInfo.WalkAnimCount * 5 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_7", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 5, CurPokemonInfo.WalkAnimCount * 6 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_4", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 6, CurPokemonInfo.WalkAnimCount * 7 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_1", CurPokemonInfo.PokemonName + "_Walk.png", CurPokemonInfo.WalkAnimCount * 7, CurPokemonInfo.WalkAnimCount * 8 - 1, WalkFrame);

	//	Attack
	float AttackFrame = 0.5f / CurPokemonInfo.AttackAnimCount;
	SpriteRenderer->CreateAnimation("AttackAnim_2", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 0, CurPokemonInfo.AttackAnimCount * 1 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_3", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 1, CurPokemonInfo.AttackAnimCount * 2 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_6", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 2, CurPokemonInfo.AttackAnimCount * 3 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_9", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 3, CurPokemonInfo.AttackAnimCount * 4 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_8", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 4, CurPokemonInfo.AttackAnimCount * 5 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_7", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 5, CurPokemonInfo.AttackAnimCount * 6 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_4", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 6, CurPokemonInfo.AttackAnimCount * 7 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_1", CurPokemonInfo.PokemonName + "_Attack.png", CurPokemonInfo.AttackAnimCount * 7, CurPokemonInfo.AttackAnimCount * 8 - 1, AttackFrame);
	//	Hurt
	float HurtFrame = 0.5f / CurPokemonInfo.HurtAnimCount;
	SpriteRenderer->CreateAnimation("HurtAnim_2", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 0, CurPokemonInfo.HurtAnimCount * 1 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_3", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 1, CurPokemonInfo.HurtAnimCount * 2 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_6", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 2, CurPokemonInfo.HurtAnimCount * 3 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_9", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 3, CurPokemonInfo.HurtAnimCount * 4 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_8", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 4, CurPokemonInfo.HurtAnimCount * 5 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_7", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 5, CurPokemonInfo.HurtAnimCount * 6 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_4", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 6, CurPokemonInfo.HurtAnimCount * 7 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_1", CurPokemonInfo.PokemonName + "_Hurt.png", CurPokemonInfo.HurtAnimCount * 7, CurPokemonInfo.HurtAnimCount * 8 - 1, HurtFrame);

}

