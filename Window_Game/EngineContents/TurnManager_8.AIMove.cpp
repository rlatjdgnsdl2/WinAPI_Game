#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

void ATurnManager::AIMove(float _DeltaTime) 
{
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		// 타겟위치 추가하는 코드
		CurPokemon->Move(_DeltaTime);
	}
	CurTurnType = TurnType::AI_Skill;
}