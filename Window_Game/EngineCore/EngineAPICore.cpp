#include "PreCompile.h"
#include "EngineAPICore.h"
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>

UEngineAPICore* UEngineAPICore::MainCore = nullptr;
UEngineContentsCore* UEngineAPICore::UserCore = nullptr;


UEngineAPICore::UEngineAPICore()
{

}

UEngineAPICore::~UEngineAPICore()
{
	std::map<std::string, class ULevel*>::iterator StartIter = Levels.begin();
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}

	Levels.clear();
}


int UEngineAPICore::EngineStart(HINSTANCE _Inst, UEngineContentsCore* _UserCore)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	UserCore = _UserCore;
	UEngineWindow::EngineWindowInit(_Inst);

	UEngineAPICore Core;
	MainCore = &Core;

	Core.EngineMainWindow.Open();	
	
	return UEngineWindow::WindowMessageLoop(EngineBeginPlay, EngineTick);
}

void UEngineAPICore::EngineBeginPlay()
{
	UserCore->BeginPlay();
}

void UEngineAPICore::EngineTick()
{
	//	�ǹ�x
	UserCore->Tick();
	//	�߿�
	MainCore->Tick();
}



void UEngineAPICore::Tick()
{
	DeltaTimer.TimeCheck();
	float DeltaTime = DeltaTimer.GetDeltaTime();
	if (nullptr == CurLevel)
	{
		MSGASSERT("���� �ھ ���� ������ �������� �ʾҽ��ϴ�");
		return;
	}
	CurLevel->Tick(DeltaTime);
	CurLevel->Render();
}


void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	std::string ChangeName = _LevelName.data();
	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(ChangeName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	if (EndIter == FindIter)
	{
		MSGASSERT(ChangeName + "��� �̸��� ������ �������� �ʽ��ϴ�.");
		return;
	}
	CurLevel = FindIter->second;
}
