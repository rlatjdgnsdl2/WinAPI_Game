#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

void ATurnManager::AIMove(float _DeltaTime)
{
	bool IsAllArrive = false;
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Move(_DeltaTime);
	}
	StartIter = MovePokemon.begin();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		if (CurPokemon->GetActorLocation() != CurPokemon->GetTargetLocation()) {
			return;
		}
	}
	MovePokemon.clear();
	CurTurnType = TurnType::AI_Skill;

	// MovePokemon에 있는 포켓몬들이 다 이동하면 이동
}