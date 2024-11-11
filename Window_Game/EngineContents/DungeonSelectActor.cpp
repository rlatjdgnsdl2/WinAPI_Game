#include "PreCompile.h"
#include "DungeonSelectActor.h"
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

	//	text
	for (int i = 0; i < 24; i++)
	{
		// 카메라가 움직여도 이녀석은 움직이지 않는다.
		USpriteRenderer* Sprite = CreateDefaultSubObject<USpriteRenderer>();
		TextRenderers.push_back(Sprite);
	}

}

ADungeonSelectActor::~ADungeonSelectActor() 
{

}

void ADungeonSelectActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("PlayerX : " + std::to_string(GetActorLocation().X));
	UEngineDebug::CoreOutPutString("PlayerY : " + std::to_string(GetActorLocation().Y));
	if (true == UEngineInput::GetInst().IsPress('I'))
	{
		AddActorLocation(FVector2D::UP*_DeltaTime*100.0f);
		
	}
	if (true == UEngineInput::GetInst().IsPress('J'))
	{
		AddActorLocation(FVector2D::LEFT * _DeltaTime* 100.0f);
	}
	if (true == UEngineInput::GetInst().IsPress('K'))
	{
		AddActorLocation(FVector2D::DOWN * _DeltaTime* 100.0f);
	}
	if (true == UEngineInput::GetInst().IsPress('L'))
	{
		AddActorLocation(FVector2D::RIGHT * _DeltaTime* 100.0f);
	}
}

void ADungeonSelectActor::LevelChangeStart()
{
	Super::LevelChangeStart();
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(true);
}
