#include "PreCompile.h"
#include "TurnManager.h"

#include "Pokemon.h"
#include "Player.h"

bool SortFuncD(APokemon* first, APokemon* second) {
	return first->GetCurAbility().GetSpeed() > second->GetCurAbility().GetSpeed();
}

void ATurnManager::Skill_AISelect()
{
	// speed로 정렬
	AllAIPokemon.sort(SortFuncD);
	PlayerCamp.sort(SortFuncD);
	EnemyCamp.sort(SortFuncD);
	{
		//	모든 AI포켓몬들
		for (APokemon* CurPokemon : AllAIPokemon)
		{
			bool IsFindTarget = false;
			CurPokemon->ResetCurDuration();
			FIntPoint CurTile = CurPokemon->GetTile();
			CampType CurPokemonCamp = CurPokemon->GetCamp();
			//	반대진영 리스트가져옴
			std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
			// 타켓로케이션 확인
			for (APokemon* CurComparePokemon : CompareCamp)
			{
				FIntPoint Distance = CurComparePokemon->GetTargetTile() - CurTile;
				//	근처에 적이 있다면
				if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
					CurPokemon->StartAttack();
					SkillPokemon.push_back(CurPokemon);
					IsFindTarget = true;
					break;
				}
			}
			//	근처에 적이 없다면
			if (false == IsFindTarget) {
				//	플레이어를 향해 길찾기
				FIntPoint PlayerTile = Player->GetTargetTile();
				std::list<FIntPoint> PathForPlayer = PathFinder.PathFind(CurTile, PlayerTile);
				if (!PathForPlayer.empty()) {
					auto Path = PathForPlayer.begin();
					if (++Path == PathForPlayer.end()) {
						Path = PathForPlayer.begin();
					}
					CurPokemon->SetTargetTile(*Path);
					MovePokemon.push_back(CurPokemon);
				}
			}
		}
	}


	{
		// 최종체크 - 서로서로 안겹치게 조정
		for (APokemon* CurPokemon : MovePokemon)
		{
			bool IsStand = false;
			//	나의 타겟로케이션
			FIntPoint CurTarget = CurPokemon->GetTargetTile();
			//	MovePokemon중 자신보다 스피드 빠른포켓몬이랑 타겟로케이션 겹치면 제자리
			std::vector<APokemon*>::iterator CompareIter = MovePokemon.begin();
			for (; *CompareIter != CurPokemon; CompareIter++)
			{
				APokemon* ComparePokemon = *CompareIter;
				//	나보다 빠른 포켓몬의 타겟로케이션
				FIntPoint CompareTarget = ComparePokemon->GetTargetTile();
				//	나보다 빠른 포켓몬이랑 로케이션 겹치면
				if (CurTarget == CompareTarget) {
					//	제자리걸음
					CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
					IsStand = true;
					break;
				}
			}
			//	위에 조건에 안걸렸다면
			if (!IsStand) {
				for (APokemon* ComparePokemon : SkillPokemon) {
					if (CurTarget == ComparePokemon->GetTile()) {
						CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
						break;
					}
				}
			}
			//	문제없다면 방향설정
			FVector2D Dir = (CurPokemon->GetTargetLocation() - CurPokemon->GetActorLocation()) / 72.0f;
			if (Dir != FVector2D::ZERO) {
				CurPokemon->SetDir(UContentsMath::FVector2D_To_DIR(Dir));
			}
		}
	}

	CurTurnType = TurnType::AI_Move;
	return;
}