#pragma once
//	user header
#include <EngineBase/EngineTimer.h>
#include <EnginePlatform/EngineWindow.h>
#include "Level.h"
#include "EngineContentsCore.h"
#include <EngineBase/EngineString.h>
#include <map>

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
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		if (false != Levels.contains(UpperName))
		{
			MSGASSERT("존재하는 이름의 레벨을 또 만들수 없습니다" + UpperName);
			return nullptr;
		}


		ULevel* NewLevel = new ULevel();

		// 게임 모드가 레벨의 특성을 설정하는 중요한 객체
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();
		NewLevel->SetName(UpperName);


		// 레벨을 string으로 저장하고 string으로 호출한다.
		Levels.insert({ UpperName, NewLevel });

		return NewLevel;
	}



	template<typename GameModeType, typename MainPawnType>
	void ResetLevel(std::string_view _LevelName)
	{
		// DestroyLevelName = _LevelName;
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		// 지금 당장 이녀석을 지우면 안된다.
		if (CurLevel->GetName() != UpperName)
		{
			DestroyLevel(_LevelName);
			CreateLevel<GameModeType, MainPawnType>(UpperName);
			return;
		}

		// CurLevel은 삭제되어야 한다.
		// 나의 포인터는 살아있다. CurLevel
		std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(UpperName);
		Levels.erase(FindIter);
		NextLevel = CreateLevel<GameModeType, MainPawnType>(UpperName);
		IsCurLevelReset = true;
	}


	void DestroyLevel(std::string_view _LevelName)
	{
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		if (false == Levels.contains(UpperName))
		{
			// MSGASSERT("존재하지 않는 레벨을 리셋할수 없습니다." + UpperName);
			return;
		}

		std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(UpperName);

		if (nullptr != FindIter->second)
		{
			delete FindIter->second;
			FindIter->second = nullptr;
		}

		Levels.erase(FindIter);
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
	bool IsCurLevelReset = false;

};


