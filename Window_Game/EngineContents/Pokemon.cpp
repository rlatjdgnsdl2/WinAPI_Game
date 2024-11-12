#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>
#include "GameDataManager.h"




APokemon::APokemon()
{
}

APokemon::~APokemon()
{

}


void APokemon::SetPokemon(std::string_view _PokemonName)
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
	CurCamp = CampType::Enemy;
	StartLocation = GetActorLocation();
	TargetLocation = GetActorLocation();
	SkillType CurSkillType = SkillType::NormalAttack;
	CurPokemonAbility = UGameDataManager::GetInst().GetPokemonAbility(CurPokemonName);
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

void APokemon::Hurt()
{
	SpriteRenderer->ChangeAnimation("HurtAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
}

void APokemon::AnimationSetting()
{
	//	Idle
	std::vector<int> IdleIndex_2(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_3(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_6(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_9(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_8(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_7(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_4(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<int> IdleIndex_1(CurPokemonAnimationInfo.IdleAnimCount);
	std::vector<std::vector<int>> IdleIndex = { IdleIndex_2,IdleIndex_3,IdleIndex_6,IdleIndex_9,IdleIndex_8,IdleIndex_7,IdleIndex_4,IdleIndex_1 };
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < CurPokemonAnimationInfo.IdleAnimCount; x++)
		{
			IdleIndex[y][x] = x + y * CurPokemonAnimationInfo.IdleAnimCount;
		}
	}
	std::vector<float> IdleFrame(CurPokemonAnimationInfo.IdleAnimCount, 0.1f);
	IdleFrame[0] = 0.1f * (11 - CurPokemonAnimationInfo.IdleAnimCount);
	SpriteRenderer->CreateAnimation("IdleAnim_2", CurPokemonName + "_Idle.png", IdleIndex[0], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_3", CurPokemonName + "_Idle.png", IdleIndex[1], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_6", CurPokemonName + "_Idle.png", IdleIndex[2], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_9", CurPokemonName + "_Idle.png", IdleIndex[3], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_8", CurPokemonName + "_Idle.png", IdleIndex[4], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_7", CurPokemonName + "_Idle.png", IdleIndex[5], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_4", CurPokemonName + "_Idle.png", IdleIndex[6], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_1", CurPokemonName + "_Idle.png", IdleIndex[7], IdleFrame);

	//	Walk
	float WalkFrame = 0.5f / CurPokemonAnimationInfo.WalkAnimCount;
	SpriteRenderer->CreateAnimation("WalkAnim_2", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 0, CurPokemonAnimationInfo.WalkAnimCount * 1 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_3", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 1, CurPokemonAnimationInfo.WalkAnimCount * 2 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_6", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 2, CurPokemonAnimationInfo.WalkAnimCount * 3 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_9", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 3, CurPokemonAnimationInfo.WalkAnimCount * 4 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_8", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 4, CurPokemonAnimationInfo.WalkAnimCount * 5 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_7", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 5, CurPokemonAnimationInfo.WalkAnimCount * 6 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_4", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 6, CurPokemonAnimationInfo.WalkAnimCount * 7 - 1, WalkFrame);
	SpriteRenderer->CreateAnimation("WalkAnim_1", CurPokemonName + "_Walk.png", CurPokemonAnimationInfo.WalkAnimCount * 7, CurPokemonAnimationInfo.WalkAnimCount * 8 - 1, WalkFrame);

	//	Attack
	float AttackFrame = 0.5f / CurPokemonAnimationInfo.AttackAnimCount;
	SpriteRenderer->CreateAnimation("AttackAnim_2", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 0, CurPokemonAnimationInfo.AttackAnimCount * 1 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_3", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 1, CurPokemonAnimationInfo.AttackAnimCount * 2 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_6", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 2, CurPokemonAnimationInfo.AttackAnimCount * 3 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_9", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 3, CurPokemonAnimationInfo.AttackAnimCount * 4 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_8", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 4, CurPokemonAnimationInfo.AttackAnimCount * 5 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_7", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 5, CurPokemonAnimationInfo.AttackAnimCount * 6 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_4", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 6, CurPokemonAnimationInfo.AttackAnimCount * 7 - 1, AttackFrame);
	SpriteRenderer->CreateAnimation("AttackAnim_1", CurPokemonName + "_Attack.png", CurPokemonAnimationInfo.AttackAnimCount * 7, CurPokemonAnimationInfo.AttackAnimCount * 8 - 1, AttackFrame);
	//	Hurt
	float HurtFrame = 0.5f / CurPokemonAnimationInfo.HurtAnimCount;
	SpriteRenderer->CreateAnimation("HurtAnim_2", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 0, CurPokemonAnimationInfo.HurtAnimCount * 1 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_3", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 1, CurPokemonAnimationInfo.HurtAnimCount * 2 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_6", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 2, CurPokemonAnimationInfo.HurtAnimCount * 3 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_9", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 3, CurPokemonAnimationInfo.HurtAnimCount * 4 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_8", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 4, CurPokemonAnimationInfo.HurtAnimCount * 5 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_7", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 5, CurPokemonAnimationInfo.HurtAnimCount * 6 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_4", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 6, CurPokemonAnimationInfo.HurtAnimCount * 7 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_1", CurPokemonName + "_Hurt.png", CurPokemonAnimationInfo.HurtAnimCount * 7, CurPokemonAnimationInfo.HurtAnimCount * 8 - 1, HurtFrame);

}

