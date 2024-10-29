#pragma once
#include "GameMode.h"

// 설명 :
class ULevel
{
public:
	//	EngineCore는 Level에 접근 가능
	friend class UEngineAPICore;

	// constrcuter destructer
	ULevel();
	~ULevel();
	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	//	일반
	void Tick(float _DeltaTime);
	void Render();

	//	템플릿
	template<typename ActorType>
	ActorType* SpawnActor()			// SpawnActor는 Level이 담당
	{
		ActorType* NewActor = new ActorType();
		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		ActorPtr->World = this;
		NewActor->BeginPlay();
		AllActors.push_back(NewActor);
		return NewActor;
	}

private:
	//	게임모드와 메인폰을 만들어서 게임을 준비시키는 템플릿함수
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType(); 
		MainPawn = new MainPawnType();		//	주로 Player

		//	항상 월드 세팅 먼저!
		MainPawn->World = this;
		GameMode->World = this;

		GameMode->BeginPlay();
		MainPawn->BeginPlay();

		AllActors.push_back(GameMode);
		AllActors.push_back(MainPawn);
	}

	void DoubleBuffering();
	void ScreenClear();

	//	일반
	AGameMode* GameMode = nullptr;
	AActor* MainPawn = nullptr;
	std::list<AActor*> AllActors;
};