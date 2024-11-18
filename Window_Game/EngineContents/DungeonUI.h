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

	void SetPlayer(class APlayer* _Player) {
		Player = _Player;
	}
	void SetPartner(class APlayer* _Partner) {
		Player = _Partner;
	}



protected:


private:
	class APlayer* Player;
	class APartner* Partner;
	




};

