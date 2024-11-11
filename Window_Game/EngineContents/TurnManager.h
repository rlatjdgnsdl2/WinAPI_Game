#pragma once
#include <EngineCore/GameMode.h>



//	설명: 던전내 모든것을 관리
class ATurnManager : public AGameMode
{
public:
	friend class ADungeonGameMode;
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


	void SetPlayer();
	void SetDungeon(class  ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}

	void PushEnemy(class APokemon* _Enemy) {
		EnemyCamp.push_back(_Enemy);
	}
	void PushAllPokemon(class APokemon* _Pokemon) {
		AllPokemon.push_back(_Pokemon);
	}
	void SetSpawnPos();

	void AllClear() {
		AllPokemon.clear();
		MovePokemon.clear();
		SkillPokemon.clear();
		PlayerCamp.clear();
		EnemyCamp.clear();
	}


protected:

private:
	class APlayer* Player = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;

	std::vector<class APokemon*> AllPokemon;
	std::vector<class APokemon*> PlayerCamp;
	std::vector<class APokemon*> EnemyCamp;

	std::vector<class APokemon*> MovePokemon;
	std::vector<class APokemon*> SkillPokemon;

	FVector2D PlayerMoveVec;
	DIR PlayerDir;
	TurnType CurTurnType;
	float CurDuration = 0.0f;

	SkillType PlayerSkillType;
	int PlayerInput = 0;



	//	Idle
	void PlayerSelect();
	//	Select Type
	void SelectMove(int _PlayerInput);
	void SelectSkill(int _PlayerInput);
	//	AI Check
	void Move_AISelect(float _DeltaTime);
	void Skill_AISelect(float _DeltaTime);
	//	Select Play
	void PlayerMove(float _DeltaTime);
	void PlayerSkill(float _DeltaTime);
	// AI Select Play
	void AIMove(float _DeltaTime);
	void AISkill(float _DeltaTime);

	void DebugMode(float _DeltaTime);


	//	move
	bool InitPlayerMove(DIR direction, FVector2D moveVector);




};
