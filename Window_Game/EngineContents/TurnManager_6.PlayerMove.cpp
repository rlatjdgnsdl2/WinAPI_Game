#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"
#include "MoveController.h"




void ATurnManager::PlayerMove(float _DeltaTime)
{
	//	Player move
	Player->Move(_DeltaTime);
	// �÷��̾ �̵��Ҷ� MovePokemon�� �ִ� ���ϸ� ��� ���ÿ� �̵���
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(_DeltaTime);
	}
	// �÷��̾ ����������
	FVector2D CurPlayerLocation = Player->GetActorLocation();
	FVector2D PlayerTargetLocation = Player->GetMoveController()->GetTargetLocation();
	if (CurPlayerLocation == PlayerTargetLocation)
	{
		//	MovePokemon�� �ִ� ���ϸ� ��� ������ �����ϰ�
		for (APokemon* CurPokemon : MovePokemon) {
			CurPokemon->Move(1.0f);
		}
		//	�� �̵������� MovePokemon�ʱ�ȭ
		MovePokemon.clear();

		CurTurn = TurnType::AI_Skill;
		return;
	}
}