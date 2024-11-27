#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AIMoveStart()
{
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->MoveStart();
	}
	CurTurn = TurnType::AI_Move;
}

void ATurnManager::AIMove(float _DeltaTime)
{
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(_DeltaTime);
	}
	// �̵������� �������� ��� �����ߴ��� üũ
	for (APokemon* CurPokemon : MovePokemon) {
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		FVector2D CurPokemonTargetLocation = CurPokemon->GetTargetLocation();
		if (CurPokemonLocation != CurPokemonTargetLocation) {
			return;
		}
	}
	// ���������� MovePokemon �ʱ�ȭ�ϰ� ��ų�ܰ�
	CurTurn = TurnType::AI_Move_End;
	return;
}

void ATurnManager::AIMoveEnd()
{
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Idle();
	}
	MovePokemon.clear();
	CurTurn = TurnType::AI_Skill_Start;
}
