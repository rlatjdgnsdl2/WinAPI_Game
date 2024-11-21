#include "PreCompile.h"
#include "TitleLogo.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include "Text.h"


ATitleLogo::ATitleLogo() 
{
	
}

ATitleLogo::~ATitleLogo() 
{

}

void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("TitleLogo.png");
	LogoRenderer->SetOrder(ERenderOrder::PLAYER);
	FVector2D WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation(WinSize.Half());
	LogoRenderer->SetCameraEffect(false);

	TitleText = GetWorld()->SpawnActor<AText>();
	TitleText->SetActorLocation(WinSize.Half() + FVector2D(-100, 200));
	TitleText->SetString("Press SpaceBar");
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CurDuration += _DeltaTime;
	if (IsActive()) {
		float Value = UEngineMath::Clamp(CurDuration/2.0f, 0.0f, 1.0f);
		LogoRenderer->SetSpriteScale(Value);
		
	};
}
