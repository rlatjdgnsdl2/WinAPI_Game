#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"


bool SortFunc(APokemon* first, APokemon* second) {
	if (first->GetPokemonStat().Speed > second->GetPokemonStat().Speed)
	{
		return true;
	}
	return false;
}




void ATurnManager::Move_AISelect(float _DeltaTime)
{
	// speed�� ����
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);

	//	��� AI���ϸ��
	std::list<class APokemon*> ::iterator StartIter = AllAIPokemon.begin();
	std::list<class APokemon*> ::iterator EndIter = AllAIPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		//	���� ����
		CampType CurPokemonCamp = CurPokemon->GetCurCamp();
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		std::list<class APokemon*> ::iterator CompareStartIter = CompareCamp.begin();
		std::list<class APokemon*> ::iterator CompareEndIter = CompareCamp.end();
		// Ÿ�Ϸ����̼� Ȯ��
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurComparePokemon = *CompareStartIter;
			FVector2D CompareTargetLocaton = CurComparePokemon->GetTargetLocation();
			
			
		}

		
	}

	// �����ܰ�
	CurTurnType = TurnType::Player_Move;
}

