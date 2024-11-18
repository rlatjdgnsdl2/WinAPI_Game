#pragma once
#include <EngineCore/ActorComponent.h>

//	Ό³Έν:
class USkillController :public UActorComponent
{
public:
	//	constrcuter, destructer
	USkillController();
	virtual ~USkillController();

	//	delete Function
	USkillController(const USkillController& _Other) = delete;
	USkillController(USkillController&& _Other) noexcept = delete;
	USkillController& operator=(const USkillController& _Other) = delete;
	USkillController& operator=(USkillController&& _Other) noexcept = delete;

	void SetSkill(SkillType _Skill) {
		CurSkill = _Skill;
	};
	SkillType GetSkill() const {
		return CurSkill;
	};

	void Skill(std::function<void()> Skill) {
		Skill();
	};

	void InsertSkill(std::string _SkillName, std::function<void()> Skill) {
		SkillMap.insert(std::make_pair(_SkillName, Skill));
	};
	void SetTargetPokemon(class APokemon* _TargetPokemon) {
		TargetPokemon = _TargetPokemon;
	};
	void PushTargetablePokemon(class APokemon* _TargetablePokemon) {
		TargetablePokemons.push_back(_TargetablePokemon);
	};
	void ClearTargetablePokemon() {
		TargetablePokemons.clear();
	};

	class APokemon* GetTargetPokemon() const {
		return TargetPokemon;
	};
	std::vector<class APokemon*>& GetTargetablePokemons() {
		return TargetablePokemons;
	};



protected:

private:
	SkillType CurSkill;
	std::vector<class APokemon*> TargetablePokemons;
	class APokemon* TargetPokemon;
	std::map<std::string, std::function<void()>> SkillMap;
};

