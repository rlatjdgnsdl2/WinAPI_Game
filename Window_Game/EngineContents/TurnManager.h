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
	void SetBasicUI(class ABasicUI* _BasicUI) {
		BasicUI = _BasicUI;
	}
	void SetDungeonUI(class ADungeonUI* _DungeonUI) {
		DungeonUI = _DungeonUI;
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
	TurnType GetCurTurn() { return CurTurn; }
	void SetCurTurn(TurnType _CurTurn) { CurTurn = _CurTurn; }

	void ComeBackTurn() { CurTurn = PreTurn; }

	UPathFindAStar PathFinder;
protected:

private:
	std::string CurDungeonName;

	class APlayer* Player = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;
	class ABasicUI* BasicUI = nullptr;
	class ADungeonUI* DungeonUI = nullptr;

	std::list<class APokemon*> AllAIPokemon;
	std::list<class APokemon*> PlayerCamp;
	std::list<class APokemon*> EnemyCamp;

	std::list<class APokemon*> MovePokemon;
	std::list<class APokemon*> SkillPokemon;

	FVector2D NextPotalLocation;

	TurnType CurTurn;
	TurnType PreTurn;

	FVector2D PlayerMoveDir;
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
