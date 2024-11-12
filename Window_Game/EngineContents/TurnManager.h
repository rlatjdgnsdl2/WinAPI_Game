#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/PathFindAstar.h>



//	설명: 던전내 모든것을 관리
class ATurnManager : public AGameMode, public IPathFindData
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
	void SetPlayer();

	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}
	void SetAllPokemon(std::list<class APokemon*>& _PokemonPool) {
		AllPokemon = _PokemonPool;
	}
	void SetSpawn();
	UPathFindAStar PathFinder;
protected:

private:
	class APlayer* Player = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;

	std::list<class APokemon*> AllPokemon;
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

	//	move
	bool InitPlayerMove(DIR direction, FVector2D moveVector);
	bool IsMove(const FIntPoint& _Point) override;

};
