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
		CurPokemon->ResetCurDuration();
		CurPokemon->Skill();

	}
	/*if (CurDuration > 0.5f) {

		CurDuration = 0.0f;
	}*/
	SkillPokemon.clear();
	CurTurnType = TurnType::Player_Select;
}