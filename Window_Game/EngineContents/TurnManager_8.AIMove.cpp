#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

void ATurnManager::AIMove(float _DeltaTime)
{
    for (APokemon* CurPokemon : MovePokemon) {
        CurPokemon->Move(_DeltaTime);
    }
    // �̵������� �������� ��� �����ߴ��� üũ
    for (APokemon* CurPokemon : MovePokemon) {
        if (CurPokemon->GetActorLocation() != CurPokemon->GetTargetLocation()) {
            return;
        }
    }
    // ���������� MovePokemon �ʱ�ȭ�ϰ� ��ų�ܰ�
    MovePokemon.clear();
    CurTurnType = TurnType::AI_Skill;
	return;

}