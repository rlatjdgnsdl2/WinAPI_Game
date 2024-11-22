#pragma once
#include <EngineCore/GameMode.h>



//	����: ���� �� UI
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
	bool IsNewLog() const { return IsNewLogValue; }
	void SetNewLog(bool _IsNewLog) { IsNewLogValue = _IsNewLog; }

	void IsGoingNextFloor();
	void HideNextFloorUI();

protected:
private:
	bool IsAskValue = false;
	bool IsNewLogValue = false;

	class APlayer* Player;
	class ADungeon_BSP* Dungeon;
	class ABasicUI* BasicUI;
	class ATurnManager* TurnManager;
	FVector2D UIStartPos = FVector2D(20.0f, 20.0f);

	//	��� UI
	class USpriteRenderer* UI_B = nullptr;
	class USpriteRenderer* UI_FValue = nullptr;
	class USpriteRenderer* UI_F = nullptr;
	class USpriteRenderer* UI_Lv = nullptr;
	class USpriteRenderer* UI_LvValue10 = nullptr;
	class USpriteRenderer* UI_LvValue01 = nullptr;
	class USpriteRenderer* UI_Hp = nullptr;
	class USpriteRenderer* UI_CurHpValue10 = nullptr;
	class USpriteRenderer* UI_CurHpValue01 = nullptr;
	class USpriteRenderer* UI_Slash = nullptr;
	class USpriteRenderer* UI_MaxHpValue10 = nullptr;
	class USpriteRenderer* UI_MaxHpValue01 = nullptr;
	std::vector<class USpriteRenderer* > HpBar;

	
	//	�������� �޴� ���½�
	class ABoxUI* DungeonNameUI;

	//	����������â
	class ABoxUI* Q_NextFloorUI;
	class ABoxUI* A_NextFloorUI;

	class ABoxUI* LogBoxUI;
	




	



	
	

	

	
	




};

