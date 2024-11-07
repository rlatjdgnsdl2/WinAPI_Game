#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Pokemon.h"
#include "Player.h"
#include "Dungeon.h"



void ATurnManager::PlayerMove(float _DeltaTime)
{
	//	Player move
	Player->Move(_DeltaTime);

	std::map<float, APokemon*>::iterator StartIter = MoveMaps.begin();
	std::map<float, APokemon*>::iterator EndIter = MoveMaps.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = StartIter->second;
		CurPokemon->Move(_DeltaTime);
	}

	if (Player->GetCurDuration() > 0.5f)	//도착했으면
	{

		MoveMaps.clear();
		CurTurnType = TurnType::AI_Move;
	}
}