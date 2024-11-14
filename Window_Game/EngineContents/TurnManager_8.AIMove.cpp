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
	//	�̵������� �������� ��� �����ߴ��� üũ
	StartIter = MovePokemon.begin();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		//	�Ѹ��̶� ������������ ����
		if (CurPokemonLocation != CurPokemon->GetTargetLocation()) {
			return;
		}
	}
	//	���������� MovePokemon �ʱ�ȭ�ϰ� ��ų�ܰ�
	MovePokemon.clear();
	CurTurnType = TurnType::AI_Skill;
	return;

}