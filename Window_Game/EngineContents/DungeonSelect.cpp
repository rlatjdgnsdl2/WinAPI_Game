#include "PreCompile.h"
#include "DungeonSelect.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/EngineAPICore.h>


ADungeonSelectActor::ADungeonSelectActor() 
{
	//	Box
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Select_Box.png");
	SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	SetActorLocation({ 0,0 });

}

ADungeonSelectActor::~ADungeonSelectActor() 
{

}

void ADungeonSelectActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("PlayerX : " + std::to_string(GetActorLocation().X));
	UEngineDebug::CoreOutPutString("PlayerY : " + std::to_string(GetActorLocation().Y));
	/*if (true == UEngineInput::GetInst().IsPress('W'))
	{
		AddActorLocation(FVector2D::UP*_DeltaTime*100.0f);
	}
	if (true == UEngineInput::GetInst().IsPress('A'))
	{
		AddActorLocation(FVector2D::LEFT * _DeltaTime* 100.0f);
	}
	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		AddActorLocation(FVector2D::DOWN * _DeltaTime* 100.0f);
	}
	if (true == UEngineInput::GetInst().IsPress('D'))
	{
		AddActorLocation(FVector2D::RIGHT * _DeltaTime* 100.0f);
	}*/
}

void ADungeonSelectActor::LevelChangeStart()
{
	Super::LevelChangeStart();
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(true);
}
