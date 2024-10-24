#pragma once
//	user header
#include <EnginePlatform/EngineWindow.h>

//	lib
#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")

class UContentsCore {
public:
	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;
};


//	����: �����ھ�Ŭ����
class UEngineAPICore
{
public:
	//	constrcuter, destructer
	UEngineAPICore();
	~UEngineAPICore();
	//	delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	//	static
	static int EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore);	//	���������Լ�

	//	Get
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
	//	static
	static UEngineAPICore* MainCore;	//	��𼭵� �����ھ �����ϱ� ���� static����?
	static UContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	UEngineWindow EngineMainWindow;		//	���� ���� ������
	void BeginPlay();
	void Tick();
	void Render();

};


