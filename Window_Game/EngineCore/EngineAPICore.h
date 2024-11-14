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




//	����: �����ھ�Ŭ����
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



	//	Level�� �����Լ� : Level�� EngineAPICore�� ���
	template<typename GameModeType, typename MainPawnType>
	ULevel* CreateLevel(std::string_view _LevelName)
	{
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		if (false != Levels.contains(UpperName))
		{
			MSGASSERT("�����ϴ� �̸��� ������ �� ����� �����ϴ�" + UpperName);
			return nullptr;
		}


		ULevel* NewLevel = new ULevel();

		// ���� ��尡 ������ Ư���� �����ϴ� �߿��� ��ü
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();
		NewLevel->SetName(UpperName);


		// ������ string���� �����ϰ� string���� ȣ���Ѵ�.
		Levels.insert({ UpperName, NewLevel });

		return NewLevel;
	}



	template<typename GameModeType, typename MainPawnType>
	void ResetLevel(std::string_view _LevelName)
	{
		// DestroyLevelName = _LevelName;
		std::string UpperName = UEngineString::ToUpper(_LevelName);

		// ���� ���� �̳༮�� ����� �ȵȴ�.
		if (CurLevel->GetName() != UpperName)
		{
			DestroyLevel(_LevelName);
			CreateLevel<GameModeType, MainPawnType>(UpperName);
			return;
		}

		// CurLevel�� �����Ǿ�� �Ѵ�.
		// ���� �����ʹ� ����ִ�. CurLevel
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
			// MSGASSERT("�������� �ʴ� ������ �����Ҽ� �����ϴ�." + UpperName);
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


