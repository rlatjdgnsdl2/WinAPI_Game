#include "PreCompile.h"
#include "PMDContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include "TempPlayer.h"
#include "TempGameMode.h"





PMDContentsCore::PMDContentsCore() {};
PMDContentsCore::~PMDContentsCore() {}
void PMDContentsCore::BeginPlay()
{
	//	����Ÿ��Ʋ ����
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Pokemon Mystery Dungeon: explorers of sky");

	//	������ ũ�� ����
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 256, 192*2 });
	//	��� Level����
	UEngineAPICore::GetCore()->CreateLevel<ATempGameMode, ATempPlayer>("TempLevel");

	UEngineAPICore::GetCore()->OpenLevel("TempLevel");

}
void PMDContentsCore::Tick()
{
}
;