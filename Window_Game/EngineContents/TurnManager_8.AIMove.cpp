#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

void ATurnManager::AIMove(float _DeltaTime)
{
    for (APokemon* CurPokemon : MovePokemon) {
        CurPokemon->Move(_DeltaTime);
    }
    // 이동했으면 목적지에 모두 도착했는지 체크
    for (APokemon* CurPokemon : MovePokemon) {
        if (CurPokemon->GetActorLocation() != CurPokemon->GetTargetLocation()) {
            return;
        }
    }
    // 도착했으면 MovePokemon 초기화하고 스킬단계
    MovePokemon.clear();
    CurTurnType = TurnType::AI_Skill;
	return;

}