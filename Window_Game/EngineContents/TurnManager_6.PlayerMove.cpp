#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"
#include "DungeonUI.h"



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
	FVector2D PlayerTargetLocation = Player->GetTargetLocation();
	if (CurPlayerLocation == PlayerTargetLocation)
	{
		// ��Ż��ġ���� Ȯ��
		if (CurPlayerLocation == NextPotalLocation)
		{
			//  �������� Max���̸�
			//  Game Clear
			//	UI����
			DungeonUI->IsGoingNextFloor();
			PreTurn = CurTurn;
			CurTurn = TurnType::Open_UI;
			
			//return;
			//  Dungeon->NextFloor();
			//  ��������(���� �����̴ϱ� ���� �����ؾ��ϳ�?)
		}
		
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