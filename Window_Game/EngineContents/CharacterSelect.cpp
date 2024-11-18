#include "PreCompile.h"
#include "CharacterSelect.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineWindow.h>


ACharacterSelect::ACharacterSelect()
{
	{
		FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		SetActorLocation(WindowSize.Half());

		BorderUI = CreateDefaultSubObject<USpriteRenderer>();
		BorderUI->SetSprite("MessageBox_Middle.png");
		BorderUI->SetSpriteScale();
		BorderUI->SetOrder(ERenderOrder::UI_BACKGROUND);
	}

	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Mudkip.png");
		SpriteRenderer->SetSpriteScale();
		SpriteRenderer->SetComponentLocation({-200,0});
		SpriteRenderer->SetOrder(ERenderOrder::UI_IMAGE);
		CharacterImages.insert({ "Mudkip", SpriteRenderer });
	}
}

ACharacterSelect::~ACharacterSelect()
{

}

void ACharacterSelect::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SetCameraToMainPawn(false);
}
