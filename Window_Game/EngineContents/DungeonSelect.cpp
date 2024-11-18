#include "PreCompile.h"
#include "DungeonSelect.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/EngineAPICore.h>


ADungeonSelectActor::ADungeonSelectActor() 
{
	//	Box
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Select_Box.png");
	SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	
}

ADungeonSelectActor::~ADungeonSelectActor() 
{

}

