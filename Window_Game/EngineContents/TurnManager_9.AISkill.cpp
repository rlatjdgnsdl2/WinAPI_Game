#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill()
{
	static int GCurIndex = 0;
	int MaxIndex = SkillPokemon.size();

	if (GCurIndex == MaxIndex) {
		GCurIndex = 0;
		SkillPokemon.clear();
		CurTurnType = TurnType::Player_Select;
		return;
	}
	//	AI_Skill에 입장하면 포켓몬들이 동시에 공격하는게 아니라 SKillPokemon에 들어있는대로 순서대로 공격
	APokemon* CurPokemon = SkillPokemon[GCurIndex];
	//타겟포켓몬 정하기
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
	if (CurPokemon->IsAttack()) {
		CurPokemon->Skill();
		return;
	}
	CurPokemon->SetTargetPokemon(nullptr);
	GCurIndex++;
	return;

}