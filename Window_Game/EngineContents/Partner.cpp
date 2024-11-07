#include "PreCompile.h"
#include "Partner.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/SpriteRenderer.h>






APartner::APartner()
{
	SetName("Partner");
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("SixTail_Idle.png");
	SpriteRenderer->SetSpriteScale();
	AnimationSetting();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
}

APartner::~APartner()
{

}

void APartner::LevelChangeStart()
{
	Super::LevelChangeStart();
	CurCamp = CampType::Player;
}

void APartner::AnimationSetting()
{
	//Idle
	std::vector<int> IdleIndex_2 = { 0,1,2,3 };
	std::vector<int> IdleIndex_3 = { 4,5,6,7 };
	std::vector<int> IdleIndex_6 = { 8,9,10,11 };
	std::vector<int> IdleIndex_9 = { 12,13,14,15 };
	std::vector<int> IdleIndex_8 = { 16,17,18,19 };
	std::vector<int> IdleIndex_7 = { 20,21,22,23 };
	std::vector<int> IdleIndex_4 = { 24,25,26,27 };
	std::vector<int> IdleIndex_1 = { 28,29,30,31 };
	std::vector<float> IdleFrame = { 1.0f,0.1f, 0.1f, 0.1f };
	SpriteRenderer->CreateAnimation("IdleAnim_2", "SixTail_Idle.png", IdleIndex_2, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_3", "SixTail_Idle.png", IdleIndex_3, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_6", "SixTail_Idle.png", IdleIndex_6, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_9", "SixTail_Idle.png", IdleIndex_9, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_8", "SixTail_Idle.png", IdleIndex_8, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_7", "SixTail_Idle.png", IdleIndex_7, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_4", "SixTail_Idle.png", IdleIndex_4, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_1", "SixTail_Idle.png", IdleIndex_1, IdleFrame);
	//	Walk
	SpriteRenderer->CreateAnimation("WalkAnim_2", "SixTail_Walk.png", 0, 4);
	SpriteRenderer->CreateAnimation("WalkAnim_3", "SixTail_Walk.png", 5, 9);
	SpriteRenderer->CreateAnimation("WalkAnim_6", "SixTail_Walk.png", 10, 14);
	SpriteRenderer->CreateAnimation("WalkAnim_9", "SixTail_Walk.png", 15, 19);
	SpriteRenderer->CreateAnimation("WalkAnim_8", "SixTail_Walk.png", 20, 24);
	SpriteRenderer->CreateAnimation("WalkAnim_7", "SixTail_Walk.png", 25, 29);
	SpriteRenderer->CreateAnimation("WalkAnim_4", "SixTail_Walk.png", 30, 34);
	SpriteRenderer->CreateAnimation("WalkAnim_1", "SixTail_Walk.png", 35, 39);
	//	Walk
	SpriteRenderer->CreateAnimation("AttackAnim_2", "SixTail_Attack.png", 0, 10);
	SpriteRenderer->CreateAnimation("AttackAnim_3", "SixTail_Attack.png", 11, 21);
	SpriteRenderer->CreateAnimation("AttackAnim_6", "SixTail_Attack.png", 22, 32);
	SpriteRenderer->CreateAnimation("AttackAnim_9", "SixTail_Attack.png", 33, 43);
	SpriteRenderer->CreateAnimation("AttackAnim_8", "SixTail_Attack.png", 44, 54);
	SpriteRenderer->CreateAnimation("AttackAnim_7", "SixTail_Attack.png", 55, 65);
	SpriteRenderer->CreateAnimation("AttackAnim_4", "SixTail_Attack.png", 66, 76);
	SpriteRenderer->CreateAnimation("AttackAnim_1", "SixTail_Attack.png", 77, 87);
	//	Walk
	SpriteRenderer->CreateAnimation("HurtAnim_2", "SixTail_Hurt.png", 0, 1);
	SpriteRenderer->CreateAnimation("HurtAnim_3", "SixTail_Hurt.png", 2, 3);
	SpriteRenderer->CreateAnimation("HurtAnim_6", "SixTail_Hurt.png", 4, 5);
	SpriteRenderer->CreateAnimation("HurtAnim_9", "SixTail_Hurt.png", 6, 7);
	SpriteRenderer->CreateAnimation("HurtAnim_8", "SixTail_Hurt.png", 8, 9);
	SpriteRenderer->CreateAnimation("HurtAnim_7", "SixTail_Hurt.png", 10, 11);
	SpriteRenderer->CreateAnimation("HurtAnim_4", "SixTail_Hurt.png", 12, 13);
	SpriteRenderer->CreateAnimation("HurtAnim_1", "SixTail_Hurt.png", 14, 15);
}
