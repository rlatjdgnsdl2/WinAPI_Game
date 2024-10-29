#pragma once
//	user header
#include "Level.h"
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineTimer.h>
#include "EngineContentsCore.h"

//	lib
#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")




//	����: �����ھ�Ŭ����
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
	static int EngineStart(HINSTANCE _Inst, UEngineContentsCore* _UserCore);	//	���������Լ�
	static UEngineAPICore* GetCore() { return MainCore; }				//	*MainCore ����

	//	�Ϲ�
	UEngineWindow& GetMainWindow() { return EngineMainWindow; }			//	*EngineMainwindow ����
	void OpenLevel(std::string_view _LevelName);
	float GetDeltaTime()
	{
		return DeltaTimer.GetDeltaTime();
	}

	// ���ø� �Լ�
	template<typename GameModeType, typename MainPawnType>
	ULevel* CreateLevel(std::string_view _LevelName)					//	Level�� ����(�޸𸮰���)�� EngineAPICore�� ���
	{
		ULevel* NewLevel = new ULevel();
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();
		Levels.insert({ _LevelName.data() , NewLevel });
		return NewLevel;
	}


protected:


private:
	//	static
	static UEngineAPICore* MainCore;	//	��𼭵� �����ھ �����ϱ� ���� static����
	static UEngineContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	//	�Ϲ�
	UEngineAPICore();
	void Tick();

	// �������
	UEngineWindow EngineMainWindow;		
	std::map<std::string, class ULevel*> Levels;	
	class ULevel* CurLevel = nullptr;	
	UEngineTimer DeltaTimer = UEngineTimer();

};


