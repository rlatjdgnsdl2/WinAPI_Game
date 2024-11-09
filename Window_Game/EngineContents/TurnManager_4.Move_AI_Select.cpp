#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"

void ATurnManager::Move_AISelect(float _DeltaTime)
{
	for (auto StartIter = IdleVec.begin(); StartIter != IdleVec.end(); StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		CampType CurCamp = CurPokemon->GetCurCamp();

		// Opposing camp ����
		std::vector<APokemon*>& OtherCamp = (CurCamp == CampType::Player) ? EnemyCamp : PlayerCamp;

		bool IsFindTarget = false;

		for (auto OtherCampIter = OtherCamp.begin(); OtherCampIter != OtherCamp.end(); OtherCampIter++)
		{
			APokemon* ComparePokemon = *OtherCampIter;
			FVector2D CompareLocation = ComparePokemon->GetActorLocation();
			FVector2D Distance = CompareLocation - CurPokemonLocation;

			// �� ĭ ���� �ִ��� Ȯ��
			if (Distance.X <= 72 && Distance.Y <= 72 && Distance.X >= -72 && Distance.Y >= -72)
			{
				SkillVec.push_back(CurPokemon);
				IsFindTarget = true;
				break;  // Ÿ���� ã���� �ݺ� ����
			}
		}

		if (!IsFindTarget)
		{
			MoveVec.push_back(CurPokemon);
			//AI�� ��� �����ϰ��� ���������
			
		}
	}


	// �����ܰ�
	CurTurnType = TurnType::Player_Move;
}