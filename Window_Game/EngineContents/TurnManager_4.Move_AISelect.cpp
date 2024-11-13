#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"

// 스피드 순으로 정렬
bool SortFunc(APokemon* first, APokemon* second) {
	if (first->GetPokemonStat().Speed > second->GetPokemonStat().Speed)
	{
		return true;
	}
	return false;
}


void ATurnManager::Move_AISelect()
{
	// speed로 정렬
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);
	{
		//	모든 AI포켓몬들
		std::list<APokemon*>::iterator StartIter = AllAIPokemon.begin();
		std::list<APokemon*> ::iterator EndIter = AllAIPokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			bool IsFindTarget = false;
			APokemon* CurPokemon = *StartIter;
			CurPokemon->ResetCurDuration();
			FIntPoint CurTile = CurPokemon->GetCurTile();
			//	진영체크
			CampType CurPokemonCamp = CurPokemon->GetCurCamp();
			//	반대진영 리스트가져옴
			std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
			std::list<APokemon*> ::iterator CompareStartIter = CompareCamp.begin();
			std::list<APokemon*> ::iterator CompareEndIter = CompareCamp.end();
			// 타켓로케이션 확인
			for (; CompareStartIter != CompareEndIter; CompareStartIter++)
			{
				APokemon* CurComparePokemon = *CompareStartIter;
				FIntPoint CompareTargetTile = CurComparePokemon->GetTargetTile();
				FIntPoint Distance = CompareTargetTile - CurTile;
				//	근처에 적이 있다면
				if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
					SkillPokemon.push_back(CurPokemon);
					//	타겟을 찾았으니까 for문 나가기
					IsFindTarget = true;
					break;
				}
			}
			//	근처에 적이 없다면
			if (false == IsFindTarget) {
				//	플레이어가 가고자 하는 위치타겟
				FIntPoint PlayerTile = Player->GetTargetTile();
				FIntPoint CurTile = CurPokemon->GetCurTile();
				//	Astar로 길찾기
				std::list<FIntPoint> PathForPlayer = PathFinder.PathFind(CurTile, PlayerTile);
				std::list<FIntPoint>::iterator Path = PathForPlayer.begin();
				std::list<FIntPoint>::iterator PathEnd = PathForPlayer.end();
				if (Path != PathEnd) {

					CurPokemon->SetStartLocation(*Path);
					Path++;
					if (Path == PathEnd) {
						Path = PathForPlayer.begin();
					}
					CurPokemon->SetTargetLocation(*Path);
					MovePokemon.push_back(CurPokemon);
				}
			}
		}

	}
	{
		// 최종체크 - 수정필요할듯
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*> ::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			std::vector<APokemon*>::iterator CompareIter = MovePokemon.begin();
			//	MovePokemon중 자신보다 스피드 빠른포켓몬이랑 타겟로케이션 겹치면 제자리
			for (; CompareIter != StartIter; CompareIter++)
			{
				APokemon* ComparePokemon = *CompareIter;
				FIntPoint CurTarget = CurPokemon->GetTargetTile();
				FIntPoint CompareTarget = ComparePokemon->GetTargetTile();
				if (CurTarget == CompareTarget) {
					CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
					break;
				}
			}
			//	SkillPokemon중 타겟로케이션 겹치면 제자리
			std::vector<APokemon*>::iterator SkillStartIter = SkillPokemon.begin();
			std::vector<APokemon*> ::iterator SkillEndIter = SkillPokemon.end();
			for (; SkillStartIter != SkillEndIter; SkillStartIter++)
			{
				APokemon* ComparePokemon = *SkillStartIter;
				FIntPoint CurTarget = CurPokemon->GetTargetTile();
				FIntPoint CompareTarget = ComparePokemon->GetCurTile();
				if (CurTarget == CompareTarget) {
					CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
					break;
				}
			}
			//	문제없다면 방향설정
			FVector2D Dir = (CurPokemon->GetTargetLocation() - CurPokemon->GetStartLocation()) / 72.0f;
			CurPokemon->SetCurDir(UContentsMath::FVector2D_To_DIR(Dir));
		}

		// 다음단계
		CurTurnType = TurnType::Player_Move;
	}
}

