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
	SpriteRenderer->SetSprite("1.Intro_Bg.png");
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
}

ATitleBackground::~ATitleBackground() {}


void ATitleBackground::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({0,0});
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
}










