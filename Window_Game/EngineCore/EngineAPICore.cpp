#include "PreCompile.h"
#include "EngineAPICore.h"
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineDelegate.h>

UEngineAPICore* UEngineAPICore::MainCore = nullptr;
UContentsCore* UEngineAPICore::UserCore = nullptr;


UEngineAPICore::UEngineAPICore()
{
	// 언리얼에서 GEngine
	MainCore = this;
}

UEngineAPICore::~UEngineAPICore()
{
}


int UEngineAPICore::EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore)
{

	UserCore = _UserCore;
	UEngineWindow::EngineWindowInit(_Inst);

	UEngineAPICore Core;

	Core.EngineMainWindow.Open();

	//auto frameFunction = std::bind(&UEngineAPICore::EngineLoop, &Core);
	return UEngineWindow::WindowMessageLoop(EngineBeginPlay, EngineTick);
}

void UEngineAPICore::EngineBeginPlay()
{
	MainCore->BeginPlay();
}

void UEngineAPICore::EngineTick()
{
	MainCore->Tick();
	MainCore->Render();
}

void UEngineAPICore::BeginPlay()
{
}

void UEngineAPICore::Tick()
{

}

void UEngineAPICore::Render()
{

}