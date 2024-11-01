#include "PreCompile.h"
#include "PMDContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>

#include "TitleGameMode.h"
#include "TempActor.h"



PMDContentsCore::PMDContentsCore() {}
PMDContentsCore::~PMDContentsCore() {}

void PMDContentsCore::BeginPlay()
{
	//	���ҽ� �ε�
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
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 256 * ScaleRate, 192 * ScaleRate });
	//	��� Level����
	UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, ATempActor>("TitleLevel");
	



	//	ó�� ���� ����
	UEngineAPICore::GetCore()->OpenLevel("TitleLevel");



}
void PMDContentsCore::Tick()
{
}
