#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class ASkillManager :public AGameMode
{
public:
	// constrcuter destructer
	virtual ~ASkillManager();

	// delete Function
	ASkillManager(const ASkillManager& _Other) = delete;
	ASkillManager(ASkillManager&& _Other) noexcept = delete;
	ASkillManager& operator=(const ASkillManager& _Other) = delete;
	ASkillManager& operator=(ASkillManager&& _Other) noexcept = delete;

	static ASkillManager& GetInst() {
		static ASkillManager Inst;
		return Inst;
	}
	void SetAttacker(class APokemon* _Attacker) {
		SkillUser = _Attacker;
	}
	class APokemon* GetTarget() {
		return Target;
	}
	void SetTarget(class APokemon* _Target) {
		Target = _Target;
	}
	void SetDungeon(class ADungeon_BSP* _Dungeon) {
		Dungeon = _Dungeon;
	}
	void SetTurnManager(class ATurnManager* _TurnManager) {
		TurnManager = _TurnManager;
	}
	std::function<void(class APokemon* _SkillUser, class APokemon* _Targer)> GetSkillFunc(std::string_view _SkillName) {
		return SkillFunc[_SkillName.data()];
	}
	
	

protected:

private:
	ASkillManager();
	class APokemon* SkillUser = nullptr;
	class APokemon* Target = nullptr;
	class ADungeon_BSP* Dungeon = nullptr;
	class ATurnManager* TurnManager = nullptr;

	std::map<std::string, std::function<void(class APokemon* _SkillUser, class APokemon* _Targer)>> SkillFunc;




};

