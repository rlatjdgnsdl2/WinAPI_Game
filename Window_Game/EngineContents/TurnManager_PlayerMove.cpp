#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Pokemon.h"
#include "Player.h"
#include "Dungeon.h"



void ATurnManager::PlayerMove(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	//	Player move
	Player->Move();

	std::map<float, APokemon*>::iterator StartIter = MoveMaps.begin();
	std::map<float, APokemon*>::iterator EndIter = MoveMaps.end();

	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = StartIter->second;
		CurPokemon->Move();
	}

	if (CurDuration > 1.0f / 2.0f)	//도착했으면
	{
		MoveMaps.clear();
		CurTurnType = TurnType::AI_Move;
	}
}