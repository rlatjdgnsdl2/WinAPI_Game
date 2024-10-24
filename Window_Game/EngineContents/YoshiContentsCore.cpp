#include "PreCompile.h"
#include "YoshiContentsCore.h"

#include "PlayGameMode.h"
#include "Player.h"

void YoshiContentsCore::BeginPlay()
{
	//UEngineAPICore::GetCore()->CreateLevel("Title");
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");
	//UEngineAPICore::GetCore()->CreateLevel("End");

	UEngineAPICore::GetCore()->OpenLevel("Play");
}

void YoshiContentsCore::Tick()
{
}
