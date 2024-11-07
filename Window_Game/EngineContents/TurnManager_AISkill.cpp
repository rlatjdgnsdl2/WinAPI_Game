#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill(float _DeltaTime)
{
	std::unordered_map<float, APokemon*>::iterator StartIter = SkillMaps.begin();
	std::unordered_map<float, APokemon*>::iterator EndIter = SkillMaps.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = StartIter->second;

	}
	CurTurnType = TurnType::Player_Select;
}