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
	AllPokemon.sort(SortFunc);
	//	모든 AI포켓몬들
	std::list<class APokemon*> ::iterator StartIter = AllPokemon.begin();
	std::list<class APokemon*> ::iterator EndIter = AllPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		bool IsFindTarget = false;
		// 나의위치
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		//	나의 진영
		CampType CurCamp = CurPokemon->GetCurCamp();

		// 비교할포켓몬들
		std::list<class APokemon*> ::iterator CompareStartIter = AllPokemon.begin();
		std::list<class APokemon*> ::iterator CompareEndIter = AllPokemon.end();
		for (; CompareStartIter != CompareEndIter; CompareStartIter++)
		{
			//	나 자신이면 건너뜀
			if (StartIter == CompareStartIter) {
				continue;
			}
			//	비교할 포켓몬 
			APokemon* ComparePokemon = *CompareStartIter;
			//	비교할 포켓몬 진영
			CampType CompareCamp = ComparePokemon->GetCurCamp();
			//	나랑 다른진영이면
			if (CurCamp != CompareCamp)
			{
				//	비교할 포켓몬 위치
				FVector2D CompareLocation = ComparePokemon->GetTargetLocation();
				//	거리차이
				FVector2D Distance = CompareLocation - CurPokemonLocation;
				//	만약에 바로 앞이거나 앞에 올 예정이면
				if (Distance.X <= 72 && Distance.Y <= 72 && Distance.Y >= -72 && Distance.Y >= -72)
				{
					//	SkillVec에 넣어줌
					IsFindTarget = true;
					//	타겟설정
					CurPokemon->SetTargetPokemon(ComparePokemon);
					SkillPokemon.push_back(CurPokemon);
					//	타겟을 찾음
					if (true==IsFindTarget) {
						break;
					}

				}
				
			}
			if (false == IsFindTarget) {
				MovePokemon.push_back(CurPokemon);
			}
			int a = 0;

		}

	}

	// 다음단계
	CurTurnType = TurnType::Player_Move;
}

bool ATurnManager::IsMove(const FIntPoint& _Point)
{
	FIntPoint CheckPoint = _Point;
	// 던전밖으로 나가면 false
	if (true == Dungeon->IsOver(CheckPoint)) {
		return false;
	}
	// 땅이 아니면 ture
	TileType CheckTileType = Dungeon->Tiles[CheckPoint.Y][CheckPoint.X].TileType;
	if (TileType::GROUND != CheckTileType) {
		return false;
	}

	// 다른포켓몬이 이동할 곳이면
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		FVector2D CurPokemonTargetLocation = CurPokemon->GetTargetLocation();
		if (CurPokemonTargetLocation.ConvertToPoint() == CheckPoint * 72) {
			return false;
		}
	}
	return true;
}