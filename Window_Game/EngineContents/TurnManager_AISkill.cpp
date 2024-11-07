#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill() 
{
	std::map<float, APokemon*>::iterator StartIter = SkillMaps.begin();
	std::map<float, APokemon*>::iterator EndIter = SkillMaps.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = StartIter->second;
		//CurPokemon->Skill();
	}
}