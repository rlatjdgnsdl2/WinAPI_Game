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

	



protected:


private:
	
	




};
