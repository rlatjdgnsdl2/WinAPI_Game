#include "PreCompile.h"
#include "Yoshi_Island_ContentsCore.h"
#include <EngineCore/EngineAPICore.h>
#include "PlayGameMode.h"
#include "Player.h"

Yoshi_Island_ContentsCore::Yoshi_Island_ContentsCore()
{
}

Yoshi_Island_ContentsCore::~Yoshi_Island_ContentsCore()
{
}

void Yoshi_Island_ContentsCore::BeginPlay()
{
	//UEngineAPICore::GetCore()->CreateLevel("Title");
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");
	//UEngineAPICore::GetCore()->CreateLevel("End");

	UEngineAPICore::GetCore()->OpenLevel("Play");
}

void Yoshi_Island_ContentsCore::Tick()
{
}
