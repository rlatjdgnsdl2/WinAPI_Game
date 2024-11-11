#include "PreCompile.h"
#include "DungeonSelectGameMode.h"

#include <EngineCore/SpriteRenderer.h>


ADungeonSelectGameMode::ADungeonSelectGameMode()
{
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("WorldMap.png");
	SpriteRenderer->SetSpriteScale(0.7f);
	SetActorLocation({0,0});
	FVector2D SpriteScale = SpriteRenderer->GetSpriteScale();
	SpriteRenderer->SetComponentLocation(SpriteScale*0.35f);
	SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
}

ADungeonSelectGameMode::~ADungeonSelectGameMode()
{

}

