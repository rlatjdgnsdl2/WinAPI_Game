#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "MoveController.h"

void ATurnManager::AIMove(float _DeltaTime)
{
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(_DeltaTime);
	}
	// 이동했으면 목적지에 모두 도착했는지 체크
	for (APokemon* CurPokemon : MovePokemon) {
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		FVector2D CurPokemonTargetLocation = CurPokemon->GetMoveController()->GetTargetLocation();
		if (CurPokemonLocation != CurPokemonTargetLocation) {
			return;
		}
	}
	// 도착했으면 MovePokemon 초기화하고 스킬단계
	MovePokemon.clear();
	CurTurn = TurnType::AI_Skill;
	return;

}