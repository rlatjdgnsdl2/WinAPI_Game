#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

APlayer::APlayer() 
{
	SpriteRenderer = CreateDefaultSubObject<ASpriteRenderer>();
}

APlayer::~APlayer() 
{

}
