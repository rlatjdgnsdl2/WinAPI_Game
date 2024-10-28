#include "PreCompile.h"
#include "YoshiContentsCore.h"
#include <EngineCore/EngineAPICore.h>
#include "PlayGameMode.h"
#include "Player.h"

YoshiContentsCore::YoshiContentsCore()
{
}

YoshiContentsCore::~YoshiContentsCore()
{
}

void YoshiContentsCore::BeginPlay()
{
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Yoshi's lsland");
	//UEngineAPICore::GetCore()->CreateLevel("Title");
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");
	//UEngineAPICore::GetCore()->CreateLevel("End");

	UEngineAPICore::GetCore()->OpenLevel("Play");
}

void YoshiContentsCore::Tick()
{
}
