#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill(float _DeltaTime)
{

	std::vector<APokemon*>::iterator StartIter = SkillPokemon.begin();
	std::vector<APokemon*>::iterator EndIter = SkillPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		if (CurPokemon->IsAttack() == false) {
			CurPokemon->Skill();
		}

		else if (CurPokemon->IsAttack() == true) {
			CurPokemon->Skill();
			return;
		}
	}

	SkillPokemon.clear();
	CurTurnType = TurnType::Player_Select;


}