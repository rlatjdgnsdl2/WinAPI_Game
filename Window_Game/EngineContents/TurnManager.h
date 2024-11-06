#pragma once
#include <EngineCore/GameMode.h>

enum class TurnType
{
	PlayerIdle,
	PlayerMove,
	PlayerAttack,
};


//	Ό³Έν:
class ATurnManager : public AGameMode
{
public:
	//	constrcuter, destructer
	ATurnManager();
	virtual ~ATurnManager();

	//	delete Function
	ATurnManager(const ATurnManager& _Other) = delete;
	ATurnManager(ATurnManager&& _Other) noexcept = delete;
	ATurnManager& operator=(const ATurnManager& _Other) = delete;
	ATurnManager& operator=(ATurnManager&& _Other) noexcept = delete;

	void LevelChangeStart() override;
	void Tick(float _DeltaTime) override;

	void SetSpawnPos();

	void Update();

	void SetDungeon(class ADungeon* _Dungeon) 
	{
		Dungeon = _Dungeon;
	}
	void SetPatner(class APartner* _Partner)
	{
		Partner = _Partner;
	}


protected:

private:
	class APlayer* Player;
	class APartner* Partner;

	class ADungeon* Dungeon;

	TurnType CurTurnType;

	float CurDuration = 0.0f;

	//	idle
	void PlayerIdle();

	//	move
	void InitPlayerMove(DIR direction, FVector2D moveVector);
	void SetPartnerDir();
	void PlayerMove(float _DeltaTime);

	//	attack
	void InitPlayerAttack();
	void PlayerAttack();


};
