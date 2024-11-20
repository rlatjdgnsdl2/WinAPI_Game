#include "PreCompile.h"
#include "Pokemon.h"


void APokemon::SetSkill(SkillType _Skill) {
	CurSkill = _Skill;
};
SkillType APokemon::GetSkill() const {
	return CurSkill;
};

void APokemon::SetTargetPokemon(class APokemon* _TargetPokemon) {
	TargetPokemon = _TargetPokemon;
};
void APokemon::PushTargetablePokemon(class APokemon* _TargetablePokemon) {
	TargetablePokemons.push_back(_TargetablePokemon);
};
void APokemon::ClearTargetablePokemon() {
	TargetablePokemons.clear();
};

APokemon* APokemon::GetTargetPokemon() const {
	return TargetPokemon;
};
std::vector<class APokemon*>& APokemon::GetTargetablePokemons() {
	return TargetablePokemons;
};

