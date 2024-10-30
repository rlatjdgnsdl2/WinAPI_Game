#include "PreCompile.h"
#include "TitleActor.h"


ATitleActor::ATitleActor() 
{
	SetActorLocation({ 0, 0 });
	SetActorScale({ 256, 256 });
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
}
