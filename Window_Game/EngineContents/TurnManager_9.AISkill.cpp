#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

int CurIndex = 0;

void ATurnManager::AISkill(float _DeltaTime)
{
	int MaxIndex = SkillPokemon.size();
	if (CurIndex != MaxIndex) {
		APokemon* CurPokemon = SkillPokemon[CurIndex];
		CurPokemon->Skill();
		if (CurPokemon->IsAttack() == false) {
			CurIndex++;
		}
	}


	if (CurIndex == MaxIndex) {
		CurIndex = 0;
		SkillPokemon.clear();
		CurTurnType = TurnType::Player_Select;
	}
}