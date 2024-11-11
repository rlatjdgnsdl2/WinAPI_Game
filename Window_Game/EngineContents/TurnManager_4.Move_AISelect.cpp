#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"

void ATurnManager::Move_AISelect(float _DeltaTime)
{
	//	��� AI���ϸ��
	std::vector<class APokemon*> ::iterator StartIter = AllPokemon.begin();
	std::vector<class APokemon*> ::iterator EndIter = AllPokemon.end();
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
				if (Distance.X <= 72 && Distance.Y <= 72&& Distance.Y >= -72&&Distance.Y >= -72)
				{
					//	SkillVec�� �־���
					SkillPokemon.push_back(CurPokemon);
					//	Ÿ���� ã��
					IsFindTarget = true;
					
				}	
			}
			// Ÿ�ٸ�ã����
			if (!IsFindTarget) 
			{
				
				MovePokemon.push_back(CurPokemon);
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
				if (Distance.X <= 72 && Distance.Y <= 72 && Distance.Y >= -72 && Distance.Y >= -72)
				{
					SkillPokemon.push_back(CurPokemon);
					IsFindTarget = true;
					
				}

			}
			if (!IsFindTarget)
			{
				//	Ÿ�ٷ����̼� ���������(�÷��̾� ��ġ ����)
			
				
				//	��Ʈ�ʸ� ��ġ �����ִ� �ӽ��ڵ� (��ã�� �˰��� ������ ����)
				

				MovePokemon.push_back(CurPokemon);
			}
		}
		
	}


	// �����ܰ�
	CurTurnType = TurnType::Player_Move;
}