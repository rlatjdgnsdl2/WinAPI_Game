#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"
#include "UIManager.h"




void ATurnManager::PlayerMoveStart() {
	Player->MoveStart();
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->MoveStart();
	}
	CurTurn = TurnType::Player_Move;
}


void ATurnManager::PlayerMove(float _DeltaTime)
{
	//	Player move
	Player->Move(_DeltaTime);
	// �÷��̾ �̵��Ҷ� MovePokemon�� �ִ� ���ϸ� ��� ���ÿ� �̵���
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(_DeltaTime);
	}
	FVector2D CurPlayerLocation = Player->GetActorLocation();
	FVector2D PlayerTargetLocation = Player->GetTargetLocation();
	if (CurPlayerLocation != PlayerTargetLocation) {
		return;
	}
	CurTurn = TurnType::Player_Move_End;
	return;
	
}
void ATurnManager::PlayerMoveEnd() {

	// �÷��̾ ����������
	Player->Idle();
	//	MovePokemon�� �ִ� ���ϸ� ��� ������ �����ϰ�
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(1.0f);
		CurPokemon->Idle();
	}
	//	�� �̵������� MovePokemon�ʱ�ȭ
	MovePokemon.clear();
	FVector2D CurPlayerLocation = Player->GetActorLocation();
	FVector2D NextPotalLocation = Dungeon->GetPotalLocation();
	// �÷��̾� ������ġ�� ��Ż��ġ���� Ȯ��
	if (CurPlayerLocation == NextPotalLocation) {
		//  �������� Max���̸�
		// 
		//  Game Clear
		//	UI����
		UIManager->SetCurMenuType(MenuType::OpenNextFloor);
		PreTurn = CurTurn;
		CurTurn = TurnType::Open_UI;
		return;
	}
	CurTurn = TurnType::AI_Skill_Start;
	return;
}
