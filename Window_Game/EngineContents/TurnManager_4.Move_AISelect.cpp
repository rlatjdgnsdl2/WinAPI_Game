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
	// speed로 정렬
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);

	//	모든 AI포켓몬들
	std::list<class APokemon*> ::iterator StartIter = AllAIPokemon.begin();
	std::list<class APokemon*> ::iterator EndIter = AllAIPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		//	나의 진영
		CampType CurPokemonCamp = CurPokemon->GetCurCamp();
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		std::list<class APokemon*> ::iterator CompareStartIter = CompareCamp.begin();
		std::list<class APokemon*> ::iterator CompareEndIter = CompareCamp.end();
		// 타켓로케이션 확인
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurComparePokemon = *CompareStartIter;
			FVector2D CompareTargetLocaton = CurComparePokemon->GetTargetLocation();
			
			
		}

		
	}

	// 다음단계
	CurTurnType = TurnType::Player_Move;
}

