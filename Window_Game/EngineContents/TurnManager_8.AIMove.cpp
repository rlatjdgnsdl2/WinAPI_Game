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
	//	이동했으면 목적지에 모두 도착했는지 체크
	StartIter = MovePokemon.begin();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		//	한명이라도 도착안했으면 리턴
		if (CurPokemonLocation != CurPokemon->GetTargetLocation()) {
			return;
		}
	}
	//	도착했으면 MovePokemon 초기화하고 스킬단계
	MovePokemon.clear();
	CurTurnType = TurnType::AI_Skill;
	return;

}