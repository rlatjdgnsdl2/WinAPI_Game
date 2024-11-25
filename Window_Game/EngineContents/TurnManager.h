#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/PathFindAstar.h>
#include <Enginebase/EngineRandom.h>



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
	void SetBasicUI(class ABasicUI* _BasicUI) {
		BasicUI = _BasicUI;
	}
	void SetDungeonUI(class ADungeonUI* _DungeonUI) {
		DungeonUI = _DungeonUI;
	}
	void SetPlayer(class APlayer* _Player) {
		Player = _Player;
	}
	void SetPartner(class APartner* _Partner) {
		Partner = _Partner;
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

	void ComeBackTurn() { CurTurn = PreTurn; }

	UPathFindAStar PathFinder;
	UEngineRandom Random;
protected:

private:
	class APlayer* Player = nullptr;
	class APartner* Partner = nullptr;

	class ADungeon_BSP* Dungeon = nullptr;

	class ABasicUI* BasicUI = nullptr;
	class ADungeonUI* DungeonUI = nullptr;

	std::list<class APokemon*> AllAIPokemon;
	std::list<class APokemon*> PlayerCamp;
	std::list<class APokemon*> EnemyCamp;

	std::list<class APokemon*> MovePokemon;
	std::list<class APokemon*> SkillPokemon;

	std::vector<class AItem*> Items;


	float CurDuration =0.0f;
	TurnType CurTurn;
	TurnType PreTurn;

	FVector2D PlayerMoveDir;
	int PlayerInput;

	//	Idle
	void PlayerSelect(float _DeltaTime);
	void OpenMenu();
	//	Select Type
	void SelectMove();
	void SelectSkill();
	//	AI Check
	void Move_AISelect();
	void Skill_AISelect();
	//	Select Play
	void PlayerMove(float _DeltaTime);
	void PlayerSkillStart();
	void PlayerSkill();
	void PlayerSkillEnd();

	// AI Select Play
	void AIMove(float _DeltaTime);
	void AISkillStart();
	void AISkill();
	void AISkillEnd();

	
	
	//	move
	bool InitPlayerMove(FVector2D moveVector);
	void SpawnEnemy();
	void SetItems();



};
