#pragma once
#include <EngineCore/GameMode.h>



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

	void IsGoNextFloor();

	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}
	bool IsOpenMenu() const { return IsOpenMenuValue; }

	void SetBasicUI(class ABasicUI* _BasicUI) {
		BasicUI = _BasicUI;
	}
	
protected:
private:
	bool IsOpenMenuValue = false;
	bool IsUseItemValue = false;

	class APlayer* Player;
	class ADungeon_BSP* Dungeon;
	class ABasicUI* BasicUI;
	FVector2D UIStartPos = FVector2D(20.0f, 20.0f);
	const FIntPoint Text_MaxCount = FIntPoint({30,3});

	//	상단 UI
	class USpriteRenderer* UI_B;
	class USpriteRenderer* UI_FValue;
	class USpriteRenderer* UI_F;
	class USpriteRenderer* UI_Lv;
	class USpriteRenderer* UI_LvValue10;
	class USpriteRenderer* UI_LvValue01;
	class USpriteRenderer* UI_Hp;
	class USpriteRenderer* UI_CurHpValue10;
	class USpriteRenderer* UI_CurHpValue01;
	class USpriteRenderer* UI_Slash;
	class USpriteRenderer* UI_MaxHpValue10;
	class USpriteRenderer* UI_MaxHpValue01;
	std::vector<class USpriteRenderer* > HpBar;

	class ABox* DungeonLogBox;



	// 한세트
	class ABox* NextFloorBox;
	class ABox* AnswerSelectBox;
	class AText* NextFloorText;
	class AText* Yes;
	class AText* No;


	//	메뉴 오픈시
	class ABox* DungeonNameBox;
	class AText* CurDungeonNameRenderer;


	



	
	

	

	
	




};

