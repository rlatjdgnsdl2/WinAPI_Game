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


//	설명: 엔진코어클래스
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
	static int EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore);	//	엔진시작함수
	static UEngineAPICore* GetCore()
	{
		return MainCore;
	}

	//
	UEngineWindow& GetMainWindow()
	{
		return EngineMainWindow;
	}
	template<typename GameModeType, typename MainPawnType>
	ULevel* CreateLevel(std::string_view _LevelName)
	{
		ULevel* NewLevel = new ULevel();
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();
		Levels.insert({ _LevelName.data() , NewLevel });
		return NewLevel;
	}
	void OpenLevel(std::string_view _LevelName);

protected:


private:
	//	static
	static UEngineAPICore* MainCore;	//	어디서든 엔진코어에 접근하기 위해 static설정?
	static UContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	//
	void Tick();
	
	// 
	UEngineWindow EngineMainWindow;		//	엔진 메인 윈도우
	std::map<std::string, class ULevel*> Levels;
	class ULevel* CurLevel = nullptr;

};


