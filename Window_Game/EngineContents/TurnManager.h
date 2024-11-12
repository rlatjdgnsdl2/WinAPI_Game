#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/PathFindAstar.h>



//	설명: 던전내 규칙을 관리
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

	void InitSpawn();

	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}
	void SetPlayer(class APlayer* _Player) {
		Player = _Player;
	}

	void PushPlayerCamp(class APokemon* _PlayerCampPokemon) {
		PlayerCamp.push_back(_PlayerCampPokemon);
	}

	void PushEnemyCamp(class APokemon* _EnemyCampPokemon) {
		EnemyCamp.push_back(_EnemyCampPokemon);
	}

	void SpawnEnemyPokemon();
	



	UPathFindAStar PathFinder;
protected:

private:
	class APlayer* Player = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;

	std::list<class APokemon*> AllAIPokemon;
	std::list<class APokemon*> PlayerCamp;
	std::list<class APokemon*> EnemyCamp;

	std::vector<class APokemon*> MovePokemon;
	std::vector<class APokemon*> SkillPokemon;


	TurnType CurTurnType;
	FVector2D PlayerMoveDir;
	float CurDuration = 0.0f;


	//	Idle
	void PlayerSelect();
	//	Select Type
	void SelectMove();
	void SelectSkill();
	//	AI Check
	void Move_AISelect(float _DeltaTime);
	void Skill_AISelect(float _DeltaTime);
	//	Select Play
	void PlayerMove(float _DeltaTime);
	void PlayerSkill(float _DeltaTime);
	// AI Select Play
	void AIMove(float _DeltaTime);
	void AISkill(float _DeltaTime);

	//	move
	bool InitPlayerMove(FVector2D moveVector);

};
