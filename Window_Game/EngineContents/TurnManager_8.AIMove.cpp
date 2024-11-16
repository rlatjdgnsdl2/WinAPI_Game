#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "MoveController.h"

void ATurnManager::AIMove(float _DeltaTime)
{
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(_DeltaTime);
	}
	// �̵������� �������� ��� �����ߴ��� üũ
	for (APokemon* CurPokemon : MovePokemon) {
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		FVector2D CurPokemonTargetLocation = CurPokemon->GetMoveController()->GetTargetLocation();
		if (CurPokemonLocation != CurPokemonTargetLocation) {
			return;
		}
	}
	// ���������� MovePokemon �ʱ�ȭ�ϰ� ��ų�ܰ�
	MovePokemon.clear();
	CurTurn = TurnType::AI_Skill;
	return;

}