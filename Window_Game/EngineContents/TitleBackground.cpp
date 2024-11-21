#include "PreCompile.h"
#include "TitleBackground.h"


#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

#include "TitleGameMode.h"



ATitleBackground::ATitleBackground()
{
	BgRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BgRenderer->SetSprite("1.Intro_Bg.png");
	BgRenderer->SetOrder(ERenderOrder::BACKGROUND);

}

ATitleBackground::~ATitleBackground() {}




void ATitleBackground::LevelChangeStart()
{
	Super::LevelChangeStart();
	SetActorLocation({0,0});
	FVector2D TitleScale = BgRenderer->SetSpriteScale();
	BgRenderer->SetComponentLocation(TitleScale.Half());
	
}










