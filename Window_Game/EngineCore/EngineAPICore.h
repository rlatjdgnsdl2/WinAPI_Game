#pragma once
//	user header
#include <EngineBase/EngineTimer.h>
#include <EnginePlatform/EngineWindow.h>
#include "Level.h"
#include "EngineContentsCore.h"

//	lib
#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")




//	설명: 엔진코어클래스
class UEngineAPICore
{
public:
	//	constrcuter, destructer
	~UEngineAPICore();
	//	delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	//	static
	static int EngineStart(HINSTANCE _Inst, UEngineContentsCore* _UserCore);
	static UEngineAPICore* GetCore() { return MainCore; }

	UEngineWindow& GetMainWindow() { return EngineMainWindow; }
	float GetDeltaTime() { return DeltaTimer.GetDeltaTime(); }



	//	Level의 생성함수 : Level은 EngineAPICore가 담당
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
	UEngineAPICore();
	//	static
	static UEngineAPICore* MainCore;
	static UEngineContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	void Tick();

	UEngineWindow EngineMainWindow;
	UEngineTimer DeltaTimer;

	//	Level
	std::map<std::string, class ULevel*> Levels;
	class ULevel* CurLevel = nullptr;
	class ULevel* NextLevel = nullptr;

};


