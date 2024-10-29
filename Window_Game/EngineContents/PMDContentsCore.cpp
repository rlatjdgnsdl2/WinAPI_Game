#include "PreCompile.h"
#include "PMDContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include "TempPlayer.h"
#include "TempGameMode.h"





PMDContentsCore::PMDContentsCore() {};
PMDContentsCore::~PMDContentsCore() {}
void PMDContentsCore::BeginPlay()
{
	//	게임타이틀 설정
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Pokemon Mystery Dungeon : Explorers of Sky");
	//	윈도우 크기 설정
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 256 * ScaleRate, 192 * ScaleRate });
	//	모든 Level생성
	UEngineAPICore::GetCore()->CreateLevel<ATempGameMode, ATempPlayer>("TempLevel");



	//	처음 레벨 입장
	UEngineAPICore::GetCore()->OpenLevel("TempLevel");

	

}
void PMDContentsCore::Tick()
{
}
;