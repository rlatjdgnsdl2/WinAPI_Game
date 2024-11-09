#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	std::vector<APokemon*>::iterator StartIter = SkillVec.begin();
	std::vector<APokemon*>::iterator EndIter = SkillVec.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Skill(CurPokemon->GetCurSkillType());

	}
	/*if (CurDuration > 0.5f) {

		CurDuration = 0.0f;
	}*/
	CurTurnType = TurnType::Player_Select;
}