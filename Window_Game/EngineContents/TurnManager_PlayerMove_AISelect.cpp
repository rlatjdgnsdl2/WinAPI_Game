#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

void ATurnManager::PlayerMove_AISelect(float _DeltaTime)
{
	std::map<float, APokemon*>::iterator StartIter = IdleMaps.begin();
	std::map<float, APokemon*>::iterator EndIter = IdleMaps.end();
	for (; StartIter!=EndIter; StartIter++) 
	{
		APokemon* CurPokemon = StartIter->second;
		CampType CurCamp = CurPokemon->GetCurCamp();
	}

	

	CurTurnType = TurnType::Player_Move;
}