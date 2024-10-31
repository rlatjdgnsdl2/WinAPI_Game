#include "PreCompile.h"
#include "TitleActor.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>



ATitleActor::ATitleActor()
{
	FVector2D winSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation({ winSize.Half() });
	SetActorScale(winSize);
	SetSprite("3.Menu_bg.png");
}

ATitleActor::~ATitleActor() {}

void ATitleActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATitleActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::GetInst().IsPress('D')) {
		int a = 0;
		UEngineAPICore::GetCore()->OpenLevel("TempLevel");

	}
}
