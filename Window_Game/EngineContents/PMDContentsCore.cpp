#include "PreCompile.h"
#include "PMDContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>

#include "TitleActor.h"
#include "TitleGameMode.h"

#include "TempActor.h"
#include "TempGameMode.h"





int PMDContentsCore::ScaleRate = 3;
FVector2D PMDContentsCore::GameViewSize{ 256 * ScaleRate, 192 * ScaleRate };


PMDContentsCore::PMDContentsCore() {};
PMDContentsCore::~PMDContentsCore() {}

void PMDContentsCore::BeginPlay()
{
	//	리소스 로드
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("Resources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();

	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UImageManager::GetInst().Load(FilePath);
	}
	

	//	게임타이틀 설정
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Pokemon Mystery Dungeon : Explorers of Sky");
	//	윈도우 크기 설정
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, GameViewSize);
	
	//	모든 Level생성
	UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, ATitleActor>("TitleLevel");
	UEngineAPICore::GetCore()->CreateLevel<ATempGameMode, ATempActor>("TempLevel");



	//	처음 레벨 입장
	UEngineAPICore::GetCore()->OpenLevel("TitleLevel");



}
void PMDContentsCore::Tick()
{
}
;