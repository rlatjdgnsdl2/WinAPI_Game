#include "PreCompile.h"
#include "Player.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>


#include "DungeonGameMode.h"
#include "Dungeon.h"

APlayer::APlayer()
{
	SetName("Player");
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("MulZZangIee_Idle.png");
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	FVector2D PlayerScale = SpriteRenderer->SetSpriteScale();
	SetActorLocation({ 0, 0 });
	
	AnimationSetting();
}

APlayer::~APlayer()
{

}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());
	UEngineDebug::CoreOutPutString("TargetPos : " + TargetLocation.ToString());
	switch (CurState)
	{
	case STATE::IDLE:
		Idle(_DeltaTime);
		break;
	case STATE::WAIK:
		Walk(_DeltaTime);
		break;
	case STATE::ATTACK:
		break;
	case STATE::DAMAGE:
		break;
	default:
		break;
	}
}

void APlayer::LevelChangeStart()
{
	Super::LevelChangeStart();
	//	Player SpawnPos
	UEngineRandom Random;
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	int RoomCount = ADungeonGameMode::GetDungeon()->GetDungeonData()->Rooms.size()-1;
	int Index = Random.RandomInt(0, RoomCount );
	FVector2D RoomLocation = ADungeonGameMode::GetDungeon()->GetDungeonData()->Rooms[Index].RoomTrans.Location;
	FVector2D RoomScale = ADungeonGameMode::GetDungeon()->GetDungeonData()->Rooms[Index].RoomTrans.Scale;
	RoomLocation.ConvertToPoint();
	RoomScale.ConvertToPoint();
	FVector2D SpawnPos = FVector2D(Random.RandomInt(RoomLocation.X, RoomLocation.X + RoomScale.X-1), Random.RandomInt(RoomLocation.Y, RoomLocation.Y + RoomScale.Y-1));
	SetActorLocation(SpawnPos*72);
}

void APlayer::LevelChangeEnd()
{

}


void APlayer::AnimationSetting()
{
	//	Idle
	std::vector<int> IdleIndex_2 = { 0,1,2,3,4,5,6 };
	std::vector<int> IdleIndex_3 = { 7,8,9,10,11,12,13 };
	std::vector<int> IdleIndex_6 = { 14,15,16,17,18,19,20 };
	std::vector<int> IdleIndex_9 = { 21,22,23,24,25,26,27 };
	std::vector<int> IdleIndex_8 = { 28,29,30,31,32,33,34 };
	std::vector<int> IdleIndex_7 = { 35,36,37,38,39,40,41 };
	std::vector<int> IdleIndex_4 = { 42,43,44,45,46,47,48 };
	std::vector<int> IdleIndex_1 = { 49,50,51,52,53,54,55 };
	std::vector<float> IdleFrame = { 1.0f,0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f };
	SpriteRenderer->CreateAnimation("IdleAnim_2", "MulZZangIee_Idle.png", IdleIndex_2, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_3", "MulZZangIee_Idle.png", IdleIndex_3, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_6", "MulZZangIee_Idle.png", IdleIndex_6, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_9", "MulZZangIee_Idle.png", IdleIndex_9, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_8", "MulZZangIee_Idle.png", IdleIndex_8, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_7", "MulZZangIee_Idle.png", IdleIndex_7, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_4", "MulZZangIee_Idle.png", IdleIndex_4, IdleFrame);
	SpriteRenderer->CreateAnimation("IdleAnim_1", "MulZZangIee_Idle.png", IdleIndex_1, IdleFrame);
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
	SpriteRenderer->CreateAnimation("HurtAnim_2", "MulZZangIee_Hurt.png", 0, 1);
	SpriteRenderer->CreateAnimation("HurtAnim_3", "MulZZangIee_Hurt.png", 2, 3);
	SpriteRenderer->CreateAnimation("HurtAnim_6", "MulZZangIee_Hurt.png", 4, 5);
	SpriteRenderer->CreateAnimation("HurtAnim_9", "MulZZangIee_Hurt.png", 6, 7);
	SpriteRenderer->CreateAnimation("HurtAnim_8", "MulZZangIee_Hurt.png", 8, 9);
	SpriteRenderer->CreateAnimation("HurtAnim_7", "MulZZangIee_Hurt.png", 10, 11);
	SpriteRenderer->CreateAnimation("HurtAnim_4", "MulZZangIee_Hurt.png", 12, 13);
	SpriteRenderer->CreateAnimation("HurtAnim_1", "MulZZangIee_Hurt.png", 14, 15);
}

void APlayer::Idle(float _DeltaTime)
{
	CurDuration = 0.0f;
	SpriteRenderer->ChangeAnimation("IdleAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
	if (true == UEngineInput::GetInst().IsPress('W'))
	{
		
		CurDir = DIR::UP;
		StartLocation = GetActorLocation();
		TargetLocation = StartLocation + (FVector2D::UP * 72);
		TILETYPE TargetLocationType = ADungeonGameMode::GetDungeon()->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];
		if (TILETYPE::GROUND != TargetLocationType) 
		{
			TargetLocation = StartLocation;
			return;

		}
		CurState = STATE::WAIK;
		
	}

	if (true == UEngineInput::GetInst().IsPress('A'))
	{
		
		CurDir = DIR::LEFT;
		StartLocation = GetActorLocation();
		TargetLocation = StartLocation + (FVector2D::LEFT * 72);
		TILETYPE TargetLocationType = ADungeonGameMode::GetDungeon()->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];
		/*if (TILETYPE::GROUND != TargetLocationType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurState = STATE::WAIK;
	}

	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		
		CurDir = DIR::DOWN;
		StartLocation = GetActorLocation();
		TargetLocation = StartLocation + (FVector2D::DOWN * 72);
		TILETYPE TargetLocationType = ADungeonGameMode::GetDungeon()->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];
		/*if (TILETYPE::GROUND != TargetLocationType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurState = STATE::WAIK;
	}

	if (true == UEngineInput::GetInst().IsPress('D'))
	{
		
		CurDir = DIR::RIGHT;
		StartLocation = GetActorLocation();
		TargetLocation = StartLocation + (FVector2D::RIGHT * 72);
		TILETYPE TargetLocationType = ADungeonGameMode::GetDungeon()->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];
		/*if (TILETYPE::GROUND != TargetLocationType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurState = STATE::WAIK;
	}
}

void APlayer::Walk(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string((int)CurDir));
	SpriteRenderer->SetSpriteScale();
	FVector2D NewLocation = FVector2D::LerpClimp(StartLocation, TargetLocation, CurDuration * Speed);
	SetActorLocation(NewLocation);
	if (CurDuration > 1.0f / Speed)
	{
		CurState = STATE::IDLE;
	}
}


