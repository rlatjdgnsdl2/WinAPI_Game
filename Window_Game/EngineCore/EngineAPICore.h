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
	~UEngineAPICore();													// delete
	//	delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	//	static
	static int EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore);	//	���������Լ�
	static UEngineAPICore* GetCore() { return MainCore; }				//	*MainCore ����

	//	�Ϲ�
	UEngineWindow& GetMainWindow() { return EngineMainWindow; }			//	*EngineMainwindow ����
	void OpenLevel(std::string_view _LevelName);

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
	static UContentsCore* UserCore;
	static void EngineBeginPlay();
	static void EngineTick();

	//	�Ϲ�
	void Tick();

	// �������
	UEngineWindow EngineMainWindow;		//	���� ���� ������ - has a ����? // �����ھ�( base_2 )�� �����÷���( base_1 )�� ����������
	std::map<std::string, class ULevel*> Levels;	//	Level map
	class ULevel* CurLevel = nullptr;	//	���緹��

};


