#include "PreCompile.h"
#include "CharacterSelectGameMode.h"


#include <EngineCore/SpriteRenderer.h>


ACharacterSelectGameMode::ACharacterSelectGameMode() 
{
	BackGround = CreateDefaultSubObject<USpriteRenderer>();
	BackGround->SetSprite("CharacterSelet_bg.png");
	FVector2D Size = BackGround->SetSpriteScale();
	BackGround->SetComponentLocation(Size.Half());
	BackGround->SetOrder(ERenderOrder::UI_BackGround);
}

ACharacterSelectGameMode::~ACharacterSelectGameMode() 
{

}

