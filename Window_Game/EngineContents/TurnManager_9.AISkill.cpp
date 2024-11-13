#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

int CurIndex = 0;

void ATurnManager::AISkill()
{
	int MaxIndex = SkillPokemon.size();
	if (CurIndex != MaxIndex) {
		APokemon* CurPokemon = SkillPokemon[CurIndex];
		//타겟포켓몬 정해야함
		if (CurPokemon->GetTargetPokemon() == nullptr) {
			//자기 주변 한명 랜덤으로 Target설정
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
					//	애니메이션 방향설정
					CurPokemon->SetCurDir(UContentsMath::FIntPoint_To_DIR(Distance));
					CurPokemon->SetCurSkillType(SkillType::NormalAttack);
					//	나중엔 타켓포켓몬 여러명해서 랜덤으로 고르기
					CurPokemon->SetTargetPokemon(CurComparePokemon);
					//	타겟을 찾았으니까 for문 나가기
					break;
				}
			}
		}
		CurPokemon->Skill();
		if (CurPokemon->IsAttack() == false) {
			CurPokemon->SetTargetPokemon(nullptr);
			CurIndex++;
		}
	}


	if (CurIndex == MaxIndex) {
		CurIndex = 0;
		SkillPokemon.clear();
		CurTurnType = TurnType::Player_Select;
	}
}