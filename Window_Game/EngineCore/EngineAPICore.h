#pragma once
//	user header
#include "Level.h"
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
	static UEngineAPICore* GetCore()
	{
		return MainCore;
	}

	//
	UEngineWindow& GetMainWindow()
	{
		return EngineMainWindow;
	}

	void CreateLevel(std::string_view _LevelName)
	{
		ULevel* NewLevel = new ULevel();

		Levels.insert({ _LevelName.data() , NewLevel });
	}

protected:


private:
	//	static
	static UEngineAPICore* MainCore;	//	��𼭵� �����ھ �����ϱ� ���� static����?
	static UContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	//
	void Tick();
	
	// 
	UEngineWindow EngineMainWindow;		//	���� ���� ������
	std::map<std::string, class ULevel*> Levels;
	

};


