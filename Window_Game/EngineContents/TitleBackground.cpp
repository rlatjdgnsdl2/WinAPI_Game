#include "PreCompile.h"
#include "TitleBackground.h"


#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

#include "TitleGameMode.h"


ATitleBackground::ATitleBackground()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("1.Intro_Bg.png");
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
}

ATitleBackground::~ATitleBackground() {}


void ATitleBackground::BeginPlay()
{
	Super::BeginPlay();
	BGMPlayer = UEngineSound::Play("TitleBGM.mp3");
}

void ATitleBackground::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({0,0});
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
	
}










