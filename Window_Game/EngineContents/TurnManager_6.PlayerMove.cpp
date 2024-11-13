#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"




void ATurnManager::PlayerMove(float _DeltaTime)
{
	//	Player move
	Player->Move(_DeltaTime);
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
	//	 �÷��̾ �̵��Ҷ� MovePokemon�� �ִ� ���ϸ� ��� �̵���
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Move(_DeltaTime);
	}

	// �÷��̾ ����������
	if (Player->GetActorLocation() == Player->GetTargetLocation())	
	{
		//	MovePokemon�� �ִ� ���ϸ� ��� ������ �����ϰ�
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			CurPokemon->Move(1.0f);
			CurPokemon->ResetCurDuration();
		}
		//	�� �̵������� MovePokemon�ʱ�ȭ
		MovePokemon.clear();
		//	�����ܰ�
		CurTurnType = TurnType::AI_Move;
	}
}