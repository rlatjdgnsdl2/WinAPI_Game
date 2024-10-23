#pragma once

//	os header
#include <Windows.h>

//	user header
#include <EnginePlatform/EngineWindow.h>

//	lib
#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")

// 설명 :
class UEngineAPICore
{
public:
	// constrcuter destructer
	UEngineAPICore();
	~UEngineAPICore();
	// delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	static int EngineStart(HINSTANCE _Inst);

	UEngineAPICore* GetCore()
	{
		return MainCore;
	}

	UEngineWindow& GetMainWindow()
	{
		return EngineMainWindow;
	}

protected:

private:
	static void EngineLoop();
	static UEngineAPICore* MainCore;

	UEngineWindow EngineMainWindow; // 엔진 메인 윈도우

	
	void Tick();
	void Render();

};

