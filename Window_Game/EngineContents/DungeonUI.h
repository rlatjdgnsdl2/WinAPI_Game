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

	void ResultMessage();
	
	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}
	



protected:


private:
	class APlayer* Player;
	class ADungeon_BSP* Dungeon;
	FVector2D UIPos = FVector2D(20.0f, 20.0f);
	FIntPoint Text_MaxCount = FIntPoint({30,3});


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

	//	하단 메시지
	class USpriteRenderer* ResultMessageBox_Border;
	class USpriteRenderer* ResultMessageBox_In;
	std::vector<std::vector<class USpriteRenderer* >> ResultMessageBox_Text;



	
	

	

	
	




};

