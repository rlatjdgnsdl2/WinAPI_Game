#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

APlayer::APlayer()
{
	InitSetting();
	AnimationSetting();
}

APlayer::~APlayer()
{

}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());
	UEngineDebug::CoreOutPutString("TargetPos : " + TargetLocation.ToString());
	KeyCheck(_DeltaTime);
	Move(_DeltaTime);
	
}

void APlayer::InitSetting()
{
	SetName("Player");
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("MulZZangIee_Idle.png");
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	FVector2D PlayerScale = SpriteRenderer->SetSpriteScale();
	SetActorLocation({ 0,0 });

}
void APlayer::AnimationSetting()
{
	//	Idle
	SpriteRenderer->CreateAnimation("IdleAnim_2", "MulZZangIee_Idle.png", 0, 6);
	SpriteRenderer->CreateAnimation("IdleAnim_3", "MulZZangIee_Idle.png", 7, 13);
	SpriteRenderer->CreateAnimation("IdleAnim_6", "MulZZangIee_Idle.png", 8, 20);
	SpriteRenderer->CreateAnimation("IdleAnim_9", "MulZZangIee_Idle.png", 21, 27);
	SpriteRenderer->CreateAnimation("IdleAnim_8", "MulZZangIee_Idle.png", 28, 34);
	SpriteRenderer->CreateAnimation("IdleAnim_7", "MulZZangIee_Idle.png", 35, 41);
	SpriteRenderer->CreateAnimation("IdleAnim_4", "MulZZangIee_Idle.png", 42, 48);
	SpriteRenderer->CreateAnimation("IdleAnim_1", "MulZZangIee_Idle.png", 49, 55);
	//	Walk
	SpriteRenderer->CreateAnimation("WalkAnim_2", "MulZZangIee_Walk.png", 0, 5);
	SpriteRenderer->CreateAnimation("WalkAnim_3", "MulZZangIee_Walk.png", 6, 11);
	SpriteRenderer->CreateAnimation("WalkAnim_6", "MulZZangIee_Walk.png", 12, 17);
	SpriteRenderer->CreateAnimation("WalkAnim_9", "MulZZangIee_Walk.png", 17, 23);
	SpriteRenderer->CreateAnimation("WalkAnim_8", "MulZZangIee_Walk.png", 24, 29);
	SpriteRenderer->CreateAnimation("WalkAnim_7", "MulZZangIee_Walk.png", 30, 35);
	SpriteRenderer->CreateAnimation("WalkAnim_4", "MulZZangIee_Walk.png", 36, 41);
	SpriteRenderer->CreateAnimation("WalkAnim_1", "MulZZangIee_Walk.png", 42, 47);
	//	Attack
	SpriteRenderer->CreateAnimation("AttackAnim_2", "MulZZangIee_Attack.png", 0, 9);
	SpriteRenderer->CreateAnimation("AttackAnim_3", "MulZZangIee_Attack.png", 10, 19);
	SpriteRenderer->CreateAnimation("AttackAnim_6", "MulZZangIee_Attack.png", 20, 29);
	SpriteRenderer->CreateAnimation("AttackAnim_9", "MulZZangIee_Attack.png", 30, 39);
	SpriteRenderer->CreateAnimation("AttackAnim_8", "MulZZangIee_Attack.png", 40, 49);
	SpriteRenderer->CreateAnimation("AttackAnim_7", "MulZZangIee_Attack.png", 50, 59);
	SpriteRenderer->CreateAnimation("AttackAnim_4", "MulZZangIee_Attack.png", 60, 69);
	SpriteRenderer->CreateAnimation("AttackAnim_1", "MulZZangIee_Attack.png", 70, 79);
	//	Hurt
	SpriteRenderer->CreateAnimation("HurtAnim_6", "MulZZangIee_Hurt.png", 4, 5);
	SpriteRenderer->CreateAnimation("HurtAnim_9", "MulZZangIee_Hurt.png", 6, 7);
	SpriteRenderer->CreateAnimation("HurtAnim_8", "MulZZangIee_Hurt.png", 8, 9);
	SpriteRenderer->CreateAnimation("HurtAnim_2", "MulZZangIee_Hurt.png", 0, 1);
	SpriteRenderer->CreateAnimation("HurtAnim_3", "MulZZangIee_Hurt.png", 2, 3);
	SpriteRenderer->CreateAnimation("HurtAnim_7", "MulZZangIee_Hurt.png", 10, 11);
	SpriteRenderer->CreateAnimation("HurtAnim_4", "MulZZangIee_Hurt.png", 12, 13);
	SpriteRenderer->CreateAnimation("HurtAnim_1", "MulZZangIee_Hurt.png", 14, 15);
}

void APlayer::KeyCheck(float _DeltaTime)
{
	if (true == UEngineInput::GetInst().IsDown('W'))
	{
		FVector2D ActorLaction = GetActorLocation();
		TargetLocation = ActorLaction + (FVector2D::UP * 72);
		SpriteRenderer->ChangeAnimation("WalkAnim_8");
		SpriteRenderer->SetSpriteScale();
	}

	if (true == UEngineInput::GetInst().IsDown('A'))
	{
		FVector2D ActorLaction = GetActorLocation();
		TargetLocation = ActorLaction + (FVector2D::LEFT * 72);
		SpriteRenderer->ChangeAnimation("WalkAnim_4");
		SpriteRenderer->SetSpriteScale();
	}

	if (true == UEngineInput::GetInst().IsDown('S'))
	{
		FVector2D ActorLaction = GetActorLocation();
		TargetLocation = ActorLaction + (FVector2D::DOWN * 72);
		SpriteRenderer->ChangeAnimation("WalkAnim_2");
		SpriteRenderer->SetSpriteScale();

	}

	if (true == UEngineInput::GetInst().IsDown('D'))
	{
		FVector2D ActorLaction = GetActorLocation();
		TargetLocation = ActorLaction + (FVector2D::RIGHT * 72);
		SpriteRenderer->ChangeAnimation("WalkAnim_6");
		SpriteRenderer->SetSpriteScale();

	}

	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		SpriteRenderer->ChangeAnimation("AttackAnim_6");
		SpriteRenderer->SetSpriteScale();

	}

}

void APlayer::Move(float _DeltaTime)
{
	FVector2D ActorLoction = GetActorLocation();
	ActorLoction.Lerp(TargetLocation, _DeltaTime * Speed);
	SetActorLocation(ActorLoction);
}


