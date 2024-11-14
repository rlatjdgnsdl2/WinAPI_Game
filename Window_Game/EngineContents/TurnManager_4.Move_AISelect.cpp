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
					CurPokemon->StartAttack();
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
				if (Path == PathEnd) {
					// 플레이어캠프일때 이런경우는 플레이어랑 위치 겹치는거
					if (CurPokemonCamp == CampType::Player) {
						CurPokemon->SetStartLocation(CurPokemon->GetActorLocation());
						CurPokemon->SetTargetLocation(Player->GetStartLocation());
						MovePokemon.push_back(CurPokemon);
					}
				}
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
		// 최종체크 - 서로서로 안겹치게 조정
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*> ::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			bool IsStand = false;
			APokemon* CurPokemon = *StartIter;
			//	나의 타겟로케인션
			FIntPoint CurTarget = CurPokemon->GetTargetTile();
			//	MovePokemon중 자신보다 스피드 빠른포켓몬이랑 타겟로케이션 겹치면 제자리
			std::vector<APokemon*>::iterator CompareIter = MovePokemon.begin();
			for (; CompareIter != StartIter; CompareIter++)
			{
				APokemon* ComparePokemon = *CompareIter;
				//	나보다 빠른 포켓몬의 타겟로케이션
				FIntPoint CompareTarget = ComparePokemon->GetTargetTile();
				//	나보다 빠른 포켓몬이랑 로케이션 겹치면
				if (CurTarget == CompareTarget) {
					//	제자리걸음
					CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
					IsStand = true;
					break;
				}
			}

			//	위에 조건에 안걸렸다면
			if (IsStand = false) {
				//	SkillPokemon중 타겟로케이션 겹치면 제자리
				std::vector<APokemon*>::iterator StartIter = SkillPokemon.begin();
				std::vector<APokemon*> ::iterator EndIter = SkillPokemon.end();
				for (; StartIter != EndIter; StartIter++)
				{
					APokemon* ComparePokemon = *StartIter;
					FIntPoint CompareTarget = ComparePokemon->GetCurTile();
					if (CurTarget == CompareTarget) {
						CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
						break;
					}
				}
			}
			//	문제없다면 방향설정
			FVector2D Dir = (CurPokemon->GetTargetLocation() - CurPokemon->GetStartLocation()) / 72.0f;
			if (Dir != FVector2D::ZERO) {
				CurPokemon->SetCurDir(UContentsMath::FVector2D_To_DIR(Dir));
			}
		}



	}
	// 다음단계
	CurTurnType = TurnType::Player_Move;
	return;
}

