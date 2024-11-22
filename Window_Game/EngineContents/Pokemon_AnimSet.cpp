#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>

#include "GameDataManager.h"


void APokemon::SetAnim()
{
	AnimInfo CurAnimInfo = UGameDataManager::GetInst().GetAnimInfo(GetName());
	//	Idle
	std::vector<int> IdleIndex_2(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_3(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_6(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_9(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_8(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_7(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_4(CurAnimInfo.IdleAnimCount);
	std::vector<int> IdleIndex_1(CurAnimInfo.IdleAnimCount);
	std::vector<std::vector<int>> IdleIndex = { IdleIndex_2,IdleIndex_3,IdleIndex_6,IdleIndex_9,IdleIndex_8,IdleIndex_7,IdleIndex_4,IdleIndex_1 };
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < CurAnimInfo.IdleAnimCount; x++)
		{
			IdleIndex[y][x] = x + y * CurAnimInfo.IdleAnimCount;
		}
	}
	std::vector<float> IdleFrame(CurAnimInfo.IdleAnimCount, 0.1f);
	IdleFrame[0] = 0.1f * (11 - CurAnimInfo.IdleAnimCount);
	SpriteRenderer->CreateAnimation("IdleAnim_2", GetName() + "_Idle.png", IdleIndex[0], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_3", GetName() + "_Idle.png", IdleIndex[1], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_6", GetName() + "_Idle.png", IdleIndex[2], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_9", GetName() + "_Idle.png", IdleIndex[3], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_8", GetName() + "_Idle.png", IdleIndex[4], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_7", GetName() + "_Idle.png", IdleIndex[5], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_4", GetName() + "_Idle.png", IdleIndex[6], IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_1", GetName() + "_Idle.png", IdleIndex[7], IdleFrame);

	//	Walk
	float WalkFrame = 0.5f / CurAnimInfo.WalkAnimCount;
	SpriteRenderer->CreateAnimation("WalkAnim_2", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 0, CurAnimInfo.WalkAnimCount * 1 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_3", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 1, CurAnimInfo.WalkAnimCount * 2 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_6", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 2, CurAnimInfo.WalkAnimCount * 3 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_9", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 3, CurAnimInfo.WalkAnimCount * 4 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_8", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 4, CurAnimInfo.WalkAnimCount * 5 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_7", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 5, CurAnimInfo.WalkAnimCount * 6 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_4", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 6, CurAnimInfo.WalkAnimCount * 7 - 1, WalkFrame, false);
	SpriteRenderer->CreateAnimation("WalkAnim_1", GetName() + "_Walk.png", CurAnimInfo.WalkAnimCount * 7, CurAnimInfo.WalkAnimCount * 8 - 1, WalkFrame, false);

	//	Attack
	float AttackFrame = 0.5f / CurAnimInfo.AttackAnimCount;
	SpriteRenderer->CreateAnimation("AttackAnim_2", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 0, CurAnimInfo.AttackAnimCount * 1 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_3", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 1, CurAnimInfo.AttackAnimCount * 2 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_6", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 2, CurAnimInfo.AttackAnimCount * 3 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_9", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 3, CurAnimInfo.AttackAnimCount * 4 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_8", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 4, CurAnimInfo.AttackAnimCount * 5 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_7", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 5, CurAnimInfo.AttackAnimCount * 6 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_4", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 6, CurAnimInfo.AttackAnimCount * 7 - 1, AttackFrame, false);
	SpriteRenderer->CreateAnimation("AttackAnim_1", GetName() + "_Attack.png", CurAnimInfo.AttackAnimCount * 7, CurAnimInfo.AttackAnimCount * 8 - 1, AttackFrame, false);

	// EndAttack bind
	SpriteRenderer->SetAnimationEvent("AttackAnim_2", (CurAnimInfo.AttackAnimCount * 1 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_3", (CurAnimInfo.AttackAnimCount * 2 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_6", (CurAnimInfo.AttackAnimCount * 3 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_9", (CurAnimInfo.AttackAnimCount * 4 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_8", (CurAnimInfo.AttackAnimCount * 5 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_7", (CurAnimInfo.AttackAnimCount * 6 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_4", (CurAnimInfo.AttackAnimCount * 7 - 1), std::bind(&APokemon::EndAttack, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_1", (CurAnimInfo.AttackAnimCount * 8 - 1), std::bind(&APokemon::EndAttack, this));
	//TargetPokemon Hurt bind
	SpriteRenderer->SetAnimationEvent("AttackAnim_2", (CurAnimInfo.AttackAnimCount * 1 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_3", (CurAnimInfo.AttackAnimCount * 2 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_6", (CurAnimInfo.AttackAnimCount * 3 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_9", (CurAnimInfo.AttackAnimCount * 4 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_8", (CurAnimInfo.AttackAnimCount * 5 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_7", (CurAnimInfo.AttackAnimCount * 6 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_4", (CurAnimInfo.AttackAnimCount * 7 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));
	SpriteRenderer->SetAnimationEvent("AttackAnim_1", (CurAnimInfo.AttackAnimCount * 8 - 1) - (CurAnimInfo.AttackAnimCount / 2), std::bind(&APokemon::PlayHurtAnim, this));


	//	Hurt
	float HurtFrame = 0.3f / CurAnimInfo.HurtAnimCount;
	SpriteRenderer->CreateAnimation("HurtAnim_2", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 0, CurAnimInfo.HurtAnimCount * 1 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_3", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 1, CurAnimInfo.HurtAnimCount * 2 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_6", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 2, CurAnimInfo.HurtAnimCount * 3 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_9", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 3, CurAnimInfo.HurtAnimCount * 4 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_8", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 4, CurAnimInfo.HurtAnimCount * 5 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_7", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 5, CurAnimInfo.HurtAnimCount * 6 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_4", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 6, CurAnimInfo.HurtAnimCount * 7 - 1, HurtFrame);
	SpriteRenderer->CreateAnimation("HurtAnim_1", GetName() + "_Hurt.png", CurAnimInfo.HurtAnimCount * 7, CurAnimInfo.HurtAnimCount * 8 - 1, HurtFrame);

	float ShootFrame = 0.5f / CurAnimInfo.ShootAnimCount;
	SpriteRenderer->CreateAnimation("ShootAnim_2", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 0, CurAnimInfo.ShootAnimCount * 1 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_3", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 1, CurAnimInfo.ShootAnimCount * 2 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_6", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 2, CurAnimInfo.ShootAnimCount * 3 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_9", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 3, CurAnimInfo.ShootAnimCount * 4 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_8", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 4, CurAnimInfo.ShootAnimCount * 5 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_7", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 5, CurAnimInfo.ShootAnimCount * 6 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_4", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 6, CurAnimInfo.ShootAnimCount * 7 - 1, ShootFrame, false);
	SpriteRenderer->CreateAnimation("ShootAnim_1", GetName() + "_Shoot.png", CurAnimInfo.ShootAnimCount * 7, CurAnimInfo.ShootAnimCount * 8 - 1, ShootFrame, false);


}