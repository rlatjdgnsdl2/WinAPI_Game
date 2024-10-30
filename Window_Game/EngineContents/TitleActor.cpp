#include "PreCompile.h"
#include "TitleActor.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include "PMDContentsCore.h"


ATitleActor::ATitleActor() 
{
	SetActorLocation({ 0, 0 });
	SetActorScale(PMDContentsCore::GameViewSize);
	SetSprite("Intro_bg.png");
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
