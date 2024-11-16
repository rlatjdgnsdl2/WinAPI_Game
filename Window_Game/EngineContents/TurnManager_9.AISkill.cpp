#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"



void ATurnManager::AISkill()
{
	static int GCurIndex = 0;
	size_t MaxIndex = SkillPokemon.size();

	if (GCurIndex == MaxIndex) {
		GCurIndex = 0;
		SkillPokemon.clear();
		CurTurnType = TurnType::Player_Select;
		return;
	}
	//	AI_Skill에 입장하면 포켓몬들이 동시에 공격하는게 아니라 SKillPokemon에 들어있는대로 순서대로 공격
	APokemon* CurPokemon = *SkillPokemon.begin()+GCurIndex;
	// 타겟포켓몬 정하기

	if (CurPokemon->GetTargetPokemon() == nullptr) {
		FIntPoint CurTile = CurPokemon->GetTile();
		CampType CurPokemonCamp = CurPokemon->GetCamp();
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		for (APokemon* CurComparePokemon : CompareCamp) {
			FIntPoint Distance = CurComparePokemon->GetTargetTile() - CurTile;
			if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
				CurPokemon->SetDir(UContentsMath::FIntPoint_To_DIR(Distance));
				CurPokemon->SetSkillType(SkillType::NormalAttack);
				CurPokemon->SetTargetPokemon(CurComparePokemon);
				break;
			}
		}
	}
	if (CurPokemon != nullptr) {
		CurPokemon->Skill();
	}
	if (true == CurPokemon->IsAttack()) {
		return;
	}
	APokemon* TargetPokemon = CurPokemon->GetTargetPokemon();
	if (true == TargetPokemon->GetCurAbility().IsDie()) {
		AllAIPokemon.remove(TargetPokemon);
		SkillPokemon.remove(TargetPokemon);
		MovePokemon.remove(TargetPokemon);
		CampType CurPokemonCamp = CurPokemon->GetCamp();
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		CompareCamp.remove(TargetPokemon);
		TargetPokemon->Destroy();
	}
	CurPokemon->SetTargetPokemon(nullptr);
	GCurIndex++;
	return;
}