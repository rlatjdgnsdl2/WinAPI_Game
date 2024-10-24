#include "PreCompile.h"
#include "YoshiContentsCore.h"


void YoshiContentsCore::BeginPlay()
{
	UEngineAPICore::GetCore()->CreateLevel("Title");
	UEngineAPICore::GetCore()->CreateLevel("Play");
	UEngineAPICore::GetCore()->CreateLevel("End");
}

void YoshiContentsCore::Tick()
{
}
