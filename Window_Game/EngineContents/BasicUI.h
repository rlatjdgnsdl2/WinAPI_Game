#pragma once
#include <EngineCore/GameMode.h>

enum class MenuType {
	Menu,
	Skill,
	Item,
	Team,
	Close
};


//	설명:
class ABasicUI :public AGameMode
{
public:
	//	constrcuter, destructer
	ABasicUI();
	virtual ~ABasicUI();

	//	delete Function
	ABasicUI(const ABasicUI& _Other) = delete;
	ABasicUI(ABasicUI&& _Other) noexcept = delete;
	ABasicUI& operator=(const ABasicUI& _Other) = delete;
	ABasicUI& operator=(ABasicUI&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void LevelChangeStart()override;
	virtual void Tick(float _DeltaTime)override;

	MenuType GetCurMenuType() const { return CurMenuType; }


	void OpenMenu();
	//void OpenSkill();
	void OpenItem();
	//void OpenTeam();
	//void OpenOther();
	//void CloseMenu();


protected:

private:
	class APlayer* Player;
	MenuType CurMenuType;


	class ABox* MyInfoBox;
	class AText* PlayerName;
	class AText* PlayerHp;




	//	메뉴
	class ABox* MenuBox;
	class ABox* ItemBox;
	class ABox* SkillBox;
	class ABox* TeamBox;

	


	std::vector<std::string> MenuString;
	std::vector<class AText*> MenuStringRenderer;
	std::vector<class AText*>::iterator MenuIter;
	class AText* CurDungeonNameRenderer;

};

