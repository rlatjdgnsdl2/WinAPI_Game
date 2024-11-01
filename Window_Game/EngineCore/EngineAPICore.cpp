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
	// level delete
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
	UEngineAPICore Core;
	MainCore = &Core;
	UserCore = _UserCore;
	UEngineWindow::EngineWindowInit(_Inst);


	Core.EngineMainWindow.Open();	
	
	return UEngineWindow::WindowMessageLoop(EngineBeginPlay, EngineTick);
}

void UEngineAPICore::EngineBeginPlay()
{
	UserCore->BeginPlay();
}

void UEngineAPICore::EngineTick()
{
	//	아직의미x
	UserCore->Tick();
	//	중요
	MainCore->Tick();
}



void UEngineAPICore::Tick()
{
	if (nullptr != NextLevel)
	{

		if (nullptr != CurLevel)
		{
			CurLevel->LevelChangeEnd();
		}
		CurLevel = NextLevel;
		NextLevel->LevelChangeStart();
		NextLevel = nullptr;
		// 델타타임이 지연될수 있으므로 델타타임을 초기화
		DeltaTimer.TimeStart();
	}
	DeltaTimer.TimeCheck();
	float DeltaTime = DeltaTimer.GetDeltaTime();
	UEngineInput::GetInst().KeyCheck(DeltaTime);
	if (nullptr == CurLevel)
	{
		MSGASSERT("엔진 코어에 현재 레벨이 지정되지 않았습니다");
		return;
	}
	CurLevel->Tick(DeltaTime);
	CurLevel->Render(DeltaTime);
}


void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	std::string ChangeName = _LevelName.data();
	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(ChangeName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();
	if (EndIter == FindIter)
	{
		MSGASSERT(ChangeName + "라는 이름의 레벨은 존재하지 않습니다.");
		return;
	}
	CurLevel = FindIter->second;
}
