#include "PreCompile.h"
#include "Fade.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include "ContentsEnum.h"

AFade* AFade::MainFade = nullptr;

AFade::AFade()
{
	BackSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BackSpriteRenderer->SetOrder(ERenderOrder::FADE);
	BackSpriteRenderer->SetSprite("Fade_Full.bmp");
	FVector2D MapScale = BackSpriteRenderer->SetSpriteScale(1.0f);
	BackSpriteRenderer->SetComponentLocation(MapScale.Half());
	BackSpriteRenderer->SetCameraEffect(false);
}

AFade::~AFade()
{
}

void AFade::FadeChange()
{
	float DeltaTime = UEngineAPICore::GetCore()->GetDeltaTime();
	FadeValue += DeltaTime * 0.5F * FadeDir;
	BackSpriteRenderer->SetAlphafloat(FadeValue);
}

void AFade::Reset()
{
	BackSpriteRenderer->SetAlphafloat(1.0f);
}

// 0 => 1
void AFade::FadeIn()
{
	FadeValue = 0.0f;
	FadeDir = 1.0f;
	TimeEventer.PushEvent(2.0f , std::bind(&AFade::FadeChange, this), true, false);
}

void AFade::FadeOut()
{
	FadeValue = 1.0f;
	FadeDir = -1.0f;
	TimeEventer.PushEvent(2.0f, std::bind(&AFade::FadeChange, this), true, false);
}

void AFade::LevelChangeStart()
{
	Super::LevelChangeStart();
	MainFade = this;
}