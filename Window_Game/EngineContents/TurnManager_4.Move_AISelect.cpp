#include "PreCompile.h"
#include "TurnManager.h"


#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"
#include "MoveController.h"
#include "SkillController.h"
#include "AbilityController.h"

// 스피드 순으로 정렬
bool SortFunc(APokemon* first, APokemon* second) {
	return first->GetCurAbility()->GetSpeed() > second->GetCurAbility()->GetSpeed();
}


void ATurnManager::Move_AISelect()
{
	// speed로 정렬
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);
	UMoveController* PlayerMove = Player->GetMoveController();
	{
		//	모든 AI포켓몬들
		for (APokemon* CurPokemon : AllAIPokemon){
			UMoveController* CurAIMove = CurPokemon->GetMoveController();
			USkillController* CurAISkill = CurPokemon->GetSkillController();
			bool IsFindTarget = false;
			CurAIMove->ResetCurDuration();
			FIntPoint CurTile = CurAIMove->GetTile();
			CampType CurPokemonCamp = CurPokemon->GetCamp();
			//	플레이어편일때 플레이어가 내쪽으로 온다면 무브리스트, 플레이어랑 자리 바꾸기
			if (CurPokemonCamp == CampType::Player && PlayerMove->GetTargetTile() == CurTile) {
				CurAIMove->SetTargetLocation(Player->GetActorLocation());
				MovePokemon.push_back(CurPokemon);
				continue;
			}
			//	반대진영 리스트가져옴
			std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
			// 타켓로케이션 확인
			for (APokemon* CurComparePokemon : CompareCamp){
				FIntPoint Distance = CurComparePokemon->GetMoveController()->GetTargetTile() - CurTile;
				//	근처에 적이 있다면 스킬리스트
				if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
					IsFindTarget = true;
					CurAISkill->PushTargetablePokemon(CurComparePokemon);
					//	애니메이션 첫 프레임에 바인드가 잘 되지않아 넣음 - 추후 수정
					CurPokemon->StartAttack();
					SkillPokemon.push_back(CurPokemon);
					break;
				}
			}
			//	근처에 적이 없다면 무브리스트
			if (false == IsFindTarget) {
				//	플레이어를 향해 길찾기
				FIntPoint PlayerTile = PlayerMove->GetTargetTile();
				std::list<FIntPoint> PathForPlayer = PathFinder.PathFind(CurTile, PlayerTile);
				if (!PathForPlayer.empty()) {
					auto Path = PathForPlayer.begin();
					if (++Path == PathForPlayer.end()) {
						Path = PathForPlayer.begin();
					}
					CurAIMove->SetTargetTile(*Path);
					MovePokemon.push_back(CurPokemon);
				}
			}
		}

	}

	{
		// 최종체크 - 서로서로 안겹치게 조정
		for (APokemon* CurPokemon : MovePokemon)
		{
			UMoveController* CurAIMove = CurPokemon->GetMoveController();
			bool IsStand = false;
			FIntPoint CurTarget = CurAIMove->GetTargetTile();

			// 무브리스트 중 자신보다 스피드 빠른 포켓몬이랑 타겟로케이션 겹치면 제자리
			for (APokemon* ComparePokemon : MovePokemon)
			{
				if (ComparePokemon == CurPokemon) break;
				if (CurTarget == ComparePokemon->GetMoveController()->GetTargetTile()) {
					CurAIMove->SetTargetLocation(CurPokemon->GetActorLocation());
					IsStand = true;
					break;
				}
			}
			// 위에 조건에 안걸렸다면 스킬리스트 중 겹치는지 확인
			if (!IsStand) {
				for (APokemon* ComparePokemon : SkillPokemon) {
					if (CurTarget == ComparePokemon->GetMoveController()->GetTile()) {
						CurAIMove->SetTargetLocation(CurPokemon->GetActorLocation());
						break;
					}
				}
			}

			// 문제없다면 방향설정
			FVector2D Dir = (CurAIMove->GetTargetLocation() - CurPokemon->GetActorLocation()) / 72.0f;
			if (Dir != FVector2D::ZERO) {
				CurPokemon->SetDir(UContentsMath::FVector2D_To_DIR(Dir));
			}
		}
	}
	// 다음단계
	CurTurn = TurnType::Player_Move;
	return;
}

