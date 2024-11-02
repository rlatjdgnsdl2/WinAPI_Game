#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

APlayer::APlayer() 
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	
	SpriteRenderer->SetSprite("MulJangIee_Idle.png");
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	FVector2D PlayerScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(PlayerScale.Half());
	SpriteRenderer->CreateAnimation("IdleAnim_2", "MulJangIee_Idle.png", 0, 6);
	SpriteRenderer->CreateAnimation("IdleAnim_3", "MulJangIee_Idle.png", 7, 13);
	SpriteRenderer->CreateAnimation("IdleAnim_6", "MulJangIee_Idle.png", 8, 20);
	SpriteRenderer->CreateAnimation("IdleAnim_9", "MulJangIee_Idle.png", 21, 27);
	SpriteRenderer->CreateAnimation("IdleAnim_8", "MulJangIee_Idle.png", 28, 34);
	SpriteRenderer->CreateAnimation("IdleAnim_7", "MulJangIee_Idle.png", 35, 41);
	SpriteRenderer->CreateAnimation("IdleAnim_4", "MulJangIee_Idle.png", 42, 48);
	SpriteRenderer->CreateAnimation("IdleAnim_1", "MulJangIee_Idle.png", 49, 55);
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
	curTime += _DeltaTime;
	Super::Tick(_DeltaTime);
	KeyCheck(_DeltaTime);

	
}



void APlayer::KeyCheck(float _DeltaTime)
{

	if (true == UEngineInput::GetInst().IsPress('W'))
	{
		SpriteRenderer->ChangeAnimation("IdleAnim_8");
	
		AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
	}

	
	if (true == UEngineInput::GetInst().IsPress('A'))
	{
		SpriteRenderer->ChangeAnimation("IdleAnim_4");
		AddActorLocation(FVector2D::LEFT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		SpriteRenderer->ChangeAnimation("IdleAnim_2");
		AddActorLocation(FVector2D::DOWN * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress('D'))
	{
		SpriteRenderer->ChangeAnimation("IdleAnim_6");
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	}
}


