#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/PathFindAstar.h>

enum class TurnType
{
	Player_Select,
	Open_Menu,
	Player_Select_Move,
	Player_Select_Skill,
	Player_Move,
	Player_Skill,
	Move_AI_Select,
	Skill_AI_Select,
	AI_Move,
	AI_Skill
};

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

	virtual void BeginPlay()override;
	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd()override;
	virtual void Tick(float _DeltaTime) override;

	void InitSpawn();

	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}
	void SetPlayer(class APlayer* _Player) {
		Player = _Player;
	}

	void PushAllAIPokemon(class APokemon* _AIPokemon) {
		AllAIPokemon.push_back(_AIPokemon);
	}

	void PushPlayerCamp(class APokemon* _PlayerCampPokemon) {
		PlayerCamp.push_back(_PlayerCampPokemon);
	}

	void PushEnemyCamp(class APokemon* _EnemyCampPokemon) {
		EnemyCamp.push_back(_EnemyCampPokemon);
	}

	UPathFindAStar PathFinder;
protected:

private:
	std::string CurDungeonName;

	class APlayer* Player = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;

	std::list<class APokemon*> AllAIPokemon;
	std::list<class APokemon*> PlayerCamp;
	std::list<class APokemon*> EnemyCamp;

	std::list<class APokemon*> MovePokemon;
	std::list<class APokemon*> SkillPokemon;

	TurnType CurTurn;
	FVector2D PlayerMoveDir;
	float CurDuration;
	int PlayerInput;

	//	Idle
	void PlayerSelect();
	void OpenMenu();
	//	Select Type
	void SelectMove();
	void SelectSkill();
	//	AI Check
	void Move_AISelect();
	void Skill_AISelect();
	//	Select Play
	void PlayerMove(float _DeltaTime);
	void PlayerSkill();
	// AI Select Play
	void AIMove(float _DeltaTime);
	void AISkill();
	//	move
	bool InitPlayerMove(FVector2D moveVector);
	void SpawnEnemy();

};
