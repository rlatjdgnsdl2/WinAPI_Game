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
	void SetUIManager(class AUIManager* _UIManager) {
		UIManager = _UIManager;
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
	class AFade* Fade = nullptr;
	class AText* DungeonName = nullptr;

	class APlayer* Player = nullptr;
	class APartner* Partner = nullptr;

	class ADungeon_BSP* Dungeon = nullptr;

	//class ABasicUI* BasicUI = nullptr;
	class AUIManager* UIManager = nullptr;
	class ADungeonUI* DungeonUI = nullptr;

	std::list<class APokemon*> AllAIPokemon;
	std::list<class APokemon*> PlayerCamp;
	std::list<class APokemon*> EnemyCamp;

	std::list<class APokemon*> MovePokemon;
	std::list<class APokemon*> SkillPokemon;




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
	void PlayerMoveStart();
	void PlayerMove(float _DeltaTime);
	void PlayerMoveEnd();
	void PlayerSkillStart();
	void PlayerSkill(float _DeltaTime);
	void PlayerSkillEnd();

	// AI Select Play
	void AIMoveStart();
	void AIMove(float _DeltaTime);
	void AIMoveEnd();
	void AISkillStart();
	void AISkill(float _DeltaTime);
	void AISkillEnd();

	//	move
	bool InitPlayerMove(FVector2D moveVector);
	void SpawnEnemy();

};
