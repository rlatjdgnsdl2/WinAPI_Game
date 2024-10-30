#include "PreCompile.h"
#include "TempActor.h"
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineInput.h>


ATempActor::ATempActor() 
{
	FVector2D winSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation({ winSize.Half() });
	SetActorScale(FVector2D(11,12)*ScaleRate);
	SetSprite("English_Font.png");
}

ATempActor::~ATempActor() {}

void ATempActor::BeginPlay()
{
	
}

void ATempActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		++MySpriteIndex;
		SetSprite("English_Font.png", MySpriteIndex);
	}
	if (true == UEngineInput::GetInst().IsDown('Q'))
	{
		--MySpriteIndex;
		SetSprite("English_Font.png", MySpriteIndex);
	}
}


