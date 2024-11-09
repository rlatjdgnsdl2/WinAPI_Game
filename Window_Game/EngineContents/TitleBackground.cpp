#include "PreCompile.h"
#include "TitleBackground.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

#include "ContentsEnum.h"
#include "TitleGameMode.h"


ATitleBackground::ATitleBackground()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	SpriteRenderer->SetSprite("1.Intro_Bg.png");
	
}

ATitleBackground::~ATitleBackground() {}

void ATitleBackground::BeginPlay()
{
	Super::BeginPlay();
}

void ATitleBackground::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({0,0});
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}











