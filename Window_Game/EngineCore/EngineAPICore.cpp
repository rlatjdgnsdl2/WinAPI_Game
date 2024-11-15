#include "PreCompile.h"
#include "EngineAPICore.h"

#include <EngineBase/EngineDebug.h>
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>

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
	UEngineSound::Release();
}


int UEngineAPICore::EngineStart(HINSTANCE _Inst, UEngineContentsCore* _UserCore)
{
	//	leak monitering
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
	MainCore->Tick();
}



void UEngineAPICore::Tick()
{
	if (true == IsCurLevelReset)
	{
		delete CurLevel;
		CurLevel = nullptr;
		IsCurLevelReset = false;
	}

	//	���������� �����Ҷ�
	if (nullptr != NextLevel)
	{
		if (nullptr != CurLevel)
		{
			//	���緹���� ����
			CurLevel->LevelChangeEnd();
		}
		CurLevel = NextLevel;
		// ���������� Init����
		NextLevel->LevelChangeStart();
		NextLevel = nullptr;

		// ��ŸŸ���� �����ɼ� �����Ƿ� ��ŸŸ���� �ʱ�ȭ
		DeltaTimer.TimeStart();
	}
	//	level roops
	DeltaTimer.TimeCheck();
	float DeltaTime = DeltaTimer.GetDeltaTime();
	UEngineSound::Update();
	UEngineInput::GetInst().KeyCheck(DeltaTime);
	if (nullptr == CurLevel)
	{
		MSGASSERT("���� �ھ ���� ������ �������� �ʾҽ��ϴ�");
		return;
	}
	CurLevel->Tick(DeltaTime);
	CurLevel->Render(DeltaTime);
	CurLevel->Collision(DeltaTime);
	CurLevel->Release(DeltaTime);
}


void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	std::string UpperName = UEngineString::ToUpper(_LevelName);
	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(UpperName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();
	if (EndIter == FindIter)
	{
		MSGASSERT(UpperName + " ��� �̸��� ������ �������� �ʽ��ϴ�.");
		return;
	}
	NextLevel = FindIter->second;
}
