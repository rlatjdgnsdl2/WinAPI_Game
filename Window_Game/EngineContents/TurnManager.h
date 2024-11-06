#pragma once
#include <EngineCore/GameMode.h>

enum class TurnType
{
	PlayerIdle,
	PlayerMove,
	PlayerAttack,
	MonsterMove
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
	void Update();

	void SetDungeon(class ADungeon* _Dungeon) 
	{
		Dungeon = _Dungeon;
		int a = 0;
	}



protected:

private:
	class APlayer* Player;
	class ADungeon* Dungeon;

	TurnType CurTurnType;

	float CurDuration = 0.0f;
	void PlayerIdle(); 
	void PlayerMove(float _DeltaTime);

};
