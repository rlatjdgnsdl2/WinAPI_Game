#pragma once
#include <EngineCore/GameMode.h>
#include "Partner.h"

//	����: �ϸŴ��� ���� ���
class ADungeonGameMode : public AGameMode
{
public:
	
	//	constrcuter, destructer
	ADungeonGameMode();
	virtual ~ADungeonGameMode();

	//	delete Function
	ADungeonGameMode(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode(ADungeonGameMode&& _Other) noexcept = delete;
	ADungeonGameMode& operator=(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode& operator=(ADungeonGameMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime)override;
	void LevelChangeStart() override;
	void LevelChangeEnd()override;

	

protected:

private:
	// GameDataManger���� �޾ƿ�
	std::string CurDungeonName;
	class ATurnManager* TurnManager;
	class ADungeon_BSP* Dungeon;
	class APlayer* Player;
	class APartner* Partner;
	class AEnemy* Enemy01;
	class AEnemy* Enemy02;
	class AEnemy* Enemy03;
	class AEnemy* Enemy04;




};

