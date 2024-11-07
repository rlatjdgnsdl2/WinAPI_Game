#include "PreCompile.h"
#include "Enemy_01.h"
#include <EngineCore/SpriteRenderer.h>


AEnemy_01::AEnemy_01() 
{
	SetName("Enemy");
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Picacu_Idle.png");
	SpriteRenderer->SetSpriteScale();
	AnimationSetting();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
}

AEnemy_01::~AEnemy_01() 
{

}

void AEnemy_01::AnimationSetting()
{
	std::vector<int> IdleIndex_2 = { 0,1,2,3,4,5 };
	std::vector<int> IdleIndex_3 = { 6,7,8,9,10,11 };
	std::vector<int> IdleIndex_6 = { 12,13,14,15,16,17};
	std::vector<int> IdleIndex_9 = { 18,19,20,21,22,23 };
	std::vector<int> IdleIndex_8 = { 24,25,26,27,28,29 };
	std::vector<int> IdleIndex_7 = { 30,31,32,33,34,35 };
	std::vector<int> IdleIndex_4 = { 36,37,38,39,40,41};
	std::vector<int> IdleIndex_1 = { 42,43,44,45,46,47 };
	std::vector<float> IdleFrame = { 1.0f,0.1f, 0.1f, 0.1f, 0.1f, 0.1f};
	SpriteRenderer->CreateAnimation("IdleAnim_2", "Picacu_Idle.png", IdleIndex_2, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_3", "Picacu_Idle.png", IdleIndex_3, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_6", "Picacu_Idle.png", IdleIndex_6, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_9", "Picacu_Idle.png", IdleIndex_9, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_8", "Picacu_Idle.png", IdleIndex_8, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_7", "Picacu_Idle.png", IdleIndex_7, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_4", "Picacu_Idle.png", IdleIndex_4, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_1", "Picacu_Idle.png", IdleIndex_1, IdleFrame);
	//	Walk
	SpriteRenderer->CreateAnimation("WalkAnim_2", "Picacu_Walk.png", 0, 3);
	SpriteRenderer->CreateAnimation("WalkAnim_3", "Picacu_Walk.png", 4, 7);
	SpriteRenderer->CreateAnimation("WalkAnim_6", "Picacu_Walk.png", 8, 11);
	SpriteRenderer->CreateAnimation("WalkAnim_9", "Picacu_Walk.png", 12, 17);
	SpriteRenderer->CreateAnimation("WalkAnim_8", "Picacu_Walk.png", 16, 19);
	SpriteRenderer->CreateAnimation("WalkAnim_7", "Picacu_Walk.png", 20, 23);
	SpriteRenderer->CreateAnimation("WalkAnim_4", "Picacu_Walk.png", 24, 27);
	SpriteRenderer->CreateAnimation("WalkAnim_1", "Picacu_Walk.png", 28, 31);
	//	Attack
	SpriteRenderer->CreateAnimation("AttackAnim_2", "Picacu_Attack.png", 0, 9);
	SpriteRenderer->CreateAnimation("AttackAnim_3", "Picacu_Attack.png", 10, 19);
	SpriteRenderer->CreateAnimation("AttackAnim_6", "Picacu_Attack.png", 20, 29);
	SpriteRenderer->CreateAnimation("AttackAnim_9", "Picacu_Attack.png", 30, 39);
	SpriteRenderer->CreateAnimation("AttackAnim_8", "Picacu_Attack.png", 40, 49);
	SpriteRenderer->CreateAnimation("AttackAnim_7", "Picacu_Attack.png", 50, 59);
	SpriteRenderer->CreateAnimation("AttackAnim_4", "Picacu_Attack.png", 60, 69);
	SpriteRenderer->CreateAnimation("AttackAnim_1", "Picacu_Attack.png", 70, 79);
	//	Hurt
	SpriteRenderer->CreateAnimation("HurtAnim_2", "Picacu_Hurt.png", 0, 1);
	SpriteRenderer->CreateAnimation("HurtAnim_3", "Picacu_Hurt.png", 2, 3);
	SpriteRenderer->CreateAnimation("HurtAnim_6", "Picacu_Hurt.png", 4, 5);
	SpriteRenderer->CreateAnimation("HurtAnim_9", "Picacu_Hurt.png", 6, 7);
	SpriteRenderer->CreateAnimation("HurtAnim_8", "Picacu_Hurt.png", 8, 9);
	SpriteRenderer->CreateAnimation("HurtAnim_7", "Picacu_Hurt.png", 10, 11);
	SpriteRenderer->CreateAnimation("HurtAnim_4", "Picacu_Hurt.png", 12, 13);
	SpriteRenderer->CreateAnimation("HurtAnim_1", "Picacu_Hurt.png", 14, 15);
}
