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
	~UEngineAPICore();													// delete
	//	delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	//	static
	static int EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore);	//	엔진시작함수
	static UEngineAPICore* GetCore() { return MainCore; }				//	*MainCore 리턴

	//	일반
	UEngineWindow& GetMainWindow() { return EngineMainWindow; }			//	*EngineMainwindow 리턴
	void OpenLevel(std::string_view _LevelName);

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
	static UContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	//	일반
	void Tick();

	// 멤버변수
	UEngineWindow EngineMainWindow;		//	엔진 메인 윈도우 - has a 관계? // 엔진코어( base_2 )는 엔진플랫폼( base_1 )을 가지고있음
	std::map<std::string, class ULevel*> Levels;	//	Level map
	class ULevel* CurLevel = nullptr;	//	현재레벨

};


