#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"

void ATurnManager::Move_AISelect(float _DeltaTime)
{
	//	��� AI���ϸ��
	std::vector<class APokemon*> ::iterator StartIter = IdleVec.begin();
	std::vector<class APokemon*> ::iterator EndIter = IdleVec.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		//	�Ǿƽĺ�
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		CampType CurCamp = CurPokemon->GetCurCamp();
		//	���ΰ����϶�
		if (CampType::Player == CurCamp)
		{
			bool IsFindTarget = false;
			//	�����̶� ��ġ��
			std::vector<APokemon*>::iterator StartIter = EnemyCamp.begin();
			std::vector<APokemon*>::iterator EndIter = EnemyCamp.end();
			for (; StartIter != EndIter; StartIter++)
			{
				APokemon* ComparePokemon = *StartIter;
				FVector2D CompreLocation = ComparePokemon->GetActorLocation();
				FVector2D Distance = CompreLocation - CurPokemonLocation;
				//	��ĭ���� ������
				if (Distance <= FVector2D(72, 72) && Distance >= FVector2D(-72, -72))
				{
					//	SkillVec�� �־���
					SkillVec.push_back(CurPokemon);
					//	Ÿ���� ã��
					IsFindTarget = true;
					
				}	
			}
			// Ÿ�ٸ�ã����
			if (!IsFindTarget) 
			{
				//Ÿ�ٷ����̼� ���������(�÷��̾� ��ġ ����)
				//	��Ʈ�ʸ� ��ġ �����ִ� �ӽ��ڵ� (��ã�� �˰����� ������ ����)
				FVector2D StartLocation = CurPokemon->SetStartLocation(CurPokemon->GetActorLocation());
				FVector2D TargetLocation = CurPokemon->SetTargetLocation(Player->GetStartLocation());
				CurPokemon->SetCurDuration(0.0f);
				//MoveVec�� �־���
				MoveVec.push_back(CurPokemon);
			}
		}
		//	���͵���
		else if (CampType::Enemy == CurCamp)
		{
			bool IsFindTarget = false;
			std::vector<APokemon*>::iterator StartIter = PlayerCamp.begin();
			std::vector<APokemon*>::iterator EndIter = PlayerCamp.end();
			for (; StartIter != EndIter; StartIter++)
			{
				APokemon* ComparePokemon = *StartIter;
				FVector2D CompreLocation = ComparePokemon->GetActorLocation();
				FVector2D Distance = CompreLocation - CurPokemonLocation;
				if (Distance <= FVector2D(72, 72) && Distance >= FVector2D(-72, -72))
				{
					SkillVec.push_back(CurPokemon);
					IsFindTarget = true;
					
				}

			}
			if (!IsFindTarget)
			{
				//Ÿ�ٷ����̼� ���������(�÷��̾� ��ġ ����)
				//	��Ʈ�ʸ� ��ġ �����ִ� �ӽ��ڵ� (��ã�� �˰����� ������ ����)
				FVector2D StartLocation = CurPokemon->SetStartLocation(CurPokemon->GetActorLocation());
				FVector2D TargetLocation = CurPokemon->SetTargetLocation(StartLocation+FVector2D::UP*72);
				CurPokemon->SetCurDuration(0.0f);

				MoveVec.push_back(CurPokemon);
			}
		}
		
	}


	// �����ܰ�
	CurTurnType = TurnType::Player_Move;
}