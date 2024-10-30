#include "PreCompile.h"
#include "PMDContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>

#include <EngineContents/TitleActor.h>
#include <EngineContents/TitleGameMode.h>




int PMDContentsCore::ScaleRate = 3;
FVector2D PMDContentsCore::GameViewSize{ 256 * ScaleRate, 192 * ScaleRate };



PMDContentsCore::PMDContentsCore() {};
PMDContentsCore::~PMDContentsCore() {}
void PMDContentsCore::BeginPlay()
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("Resources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();

	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UImageManager::GetInst().Load(FilePath);
	}
	

	//	����Ÿ��Ʋ ����
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Pokemon Mystery Dungeon : Explorers of Sky");
	//	������ ũ�� ����
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, GameViewSize);
	
	//	��� Level����
	UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, ATitleActor>("TitleLevel");



	//	ó�� ���� ����
	UEngineAPICore::GetCore()->OpenLevel("TitleLevel");



}
void PMDContentsCore::Tick()
{
}
;