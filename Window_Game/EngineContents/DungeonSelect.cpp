#include "PreCompile.h"
#include "DungeonSelect.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/EngineAPICore.h>


ADungeonSelectActor::ADungeonSelectActor() 
{
	//	Box
	SelectBoxRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SelectBoxRenderer->SetSprite("Select_Box.png");
	SelectBoxRenderer->SetSpriteScale();
	SelectBoxRenderer->SetOrder(ERenderOrder::PLAYER);
	
}

ADungeonSelectActor::~ADungeonSelectActor() 
{

}

