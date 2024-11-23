#pragma once
#include <EngineCore/GameMode.h>


//	Ό³Έν:
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
	void SetCurMenuType(MenuType _CurMenuType) { CurMenuType = _CurMenuType; }

	void SetPartner(class APartner* _Partner) {
		Partner = _Partner;
	}

	void ShowMenu();
	void OpenMenu();
	void OpenSkill();
	void OpenItem();


protected:

private:
	class APlayer* Player;
	class APartner* Partner;

	MenuType CurMenuType;
	TurnType CurTurn;

	//	UI
	class ABoxUI* MenuBoxUI;
	class ABoxUI* MyInfoBoxUI;

	class ABoxUI* SkillUI;
	class ABoxUI* SkillInfoUI;



	




};

