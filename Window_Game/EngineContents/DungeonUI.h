#pragma once
#include <EngineCore/GameMode.h>
#include <EngineBase/TimeEvent.h>



//	설명: 던전 내 UI
class ADungeonUI :public AGameMode
{
public:
	//	constrcuter, destructer
	ADungeonUI();
	virtual ~ADungeonUI();
	//	delete Function
	ADungeonUI(const ADungeonUI& _Other) = delete;
	ADungeonUI(ADungeonUI&& _Other) noexcept = delete;
	ADungeonUI& operator=(const ADungeonUI& _Other) = delete;
	ADungeonUI& operator=(ADungeonUI&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void LevelChangeStart()override;
	virtual void Tick(float _DeltaTime)override;

	void CreateTopUI(const std::string& key, const std::string& spriteName, float offsetX = 0.0f);

	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}

	void SetBasicUI(class ABasicUI* _BasicUI) {
		BasicUI = _BasicUI;
	}

	bool IsAsk() const { return IsAskValue; }

	void SetTurnManager(class ATurnManager* _TurnManager) {
		TurnManager = _TurnManager;
	}

	class ABoxUI* GetLogBoxUI() { return LogBoxUI; }
	
	void NewLogMessage(const std::string_view _Message);
	void NewLogMessage(const std::vector<std::string>& _Message, const std::vector<TextColor>& _colors);
	void SetNewLogVal(bool _IsNewLog) { IsNewLogValue = _IsNewLog; }
	bool IsNewLog() const { return IsNewLogValue; }


	void IsGoingNextFloor();
	void HideNextFloorUI();

protected:
private:
	bool IsAskValue = false;
	bool IsNewLogValue = false;
	

	class APlayer* Player = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;
	class ABasicUI* BasicUI = nullptr;
	class ATurnManager* TurnManager = nullptr;
	FVector2D UIStartPos = FVector2D(20.0f, 20.0f);

	//	상단 UI
	std::unordered_map<std::string, class USpriteRenderer*> TopUI;
	std::vector<class USpriteRenderer* > HpBar;







	//	던전에서 메뉴 오픈시
	class ABoxUI* DungeonNameUI = nullptr;

	//	다음층질문창
	class ABoxUI* Q_NextFloorUI = nullptr;
	class ABoxUI* A_NextFloorUI = nullptr;

	//	전투 로그메시지
	class ABoxUI* LogBoxUI = nullptr;




















};

