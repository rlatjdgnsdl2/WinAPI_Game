#pragma once
#include "GameMode.h"

// ���� :
class ULevel
{
public:
	//	EngineCore�� Level�� ���� ����
	friend class UEngineAPICore;

	// constrcuter destructer
	ULevel();
	~ULevel();
	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	//	�Ϲ�
	void Tick(float _DeltaTime);
	void Render();

	//	���ø�
	template<typename ActorType>
	ActorType* SpawnActor()			// SpawnActor�� Level�� ���
	{
		ActorType* NewActor = new ActorType();
		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		ActorPtr->World = this;
		NewActor->BeginPlay();
		AllActors.push_back(NewActor);
		return NewActor;
	}

private:
	//	���Ӹ��� �������� ���� ������ �غ��Ű�� ���ø��Լ�
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType(); 
		MainPawn = new MainPawnType();		//	�ַ� Player

		//	�׻� ���� ���� ����!
		MainPawn->World = this;
		GameMode->World = this;

		GameMode->BeginPlay();
		MainPawn->BeginPlay();

		AllActors.push_back(GameMode);
		AllActors.push_back(MainPawn);
	}

	void DoubleBuffering();
	void ScreenClear();

	//	�Ϲ�
	AGameMode* GameMode = nullptr;
	AActor* MainPawn = nullptr;
	std::list<AActor*> AllActors;
};