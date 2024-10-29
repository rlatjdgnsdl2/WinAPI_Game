#pragma once
//	user header
#include "Level.h"
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineTimer.h>
#include "EngineContentsCore.h"

//	lib
#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")




//	설명: 엔진코어클래스
class UEngineAPICore
{
public:
	//	constrcuter, destructer
	~UEngineAPICore();													// delete
	//	delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	//	static
	static int EngineStart(HINSTANCE _Inst, UEngineContentsCore* _UserCore);	//	엔진시작함수
	static UEngineAPICore* GetCore() { return MainCore; }				//	*MainCore 리턴

	//	일반
	UEngineWindow& GetMainWindow() { return EngineMainWindow; }			//	*EngineMainwindow 리턴
	void OpenLevel(std::string_view _LevelName);
	float GetDeltaTime()
	{
		return DeltaTimer.GetDeltaTime();
	}

	// 템플릿 함수
	template<typename GameModeType, typename MainPawnType>
	ULevel* CreateLevel(std::string_view _LevelName)					//	Level의 생성(메모리관리)은 EngineAPICore가 담당
	{
		ULevel* NewLevel = new ULevel();
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();
		Levels.insert({ _LevelName.data() , NewLevel });
		return NewLevel;
	}


protected:


private:
	//	static
	static UEngineAPICore* MainCore;	//	어디서든 엔진코어에 접근하기 위해 static설정
	static UEngineContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	//	일반
	UEngineAPICore();
	void Tick();

	// 멤버변수
	UEngineWindow EngineMainWindow;		
	std::map<std::string, class ULevel*> Levels;	
	class ULevel* CurLevel = nullptr;	
	UEngineTimer DeltaTimer = UEngineTimer();

};


