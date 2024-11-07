#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill(float _DeltaTime)
{
	std::vector<APokemon*>::iterator StartIter = SkillVec.begin();
	std::vector<APokemon*>::iterator EndIter = SkillVec.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;

	}
	CurTurnType = TurnType::Player_Select;
}