#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineBase/EngineRandom.h>
#include "Pokemon.h"
#include "SkillController.h"
#include "AbilityController.h"




void ATurnManager::AISkill()
{
	size_t MaxIndex = SkillPokemon.size();
	std::list<APokemon*>::iterator StartIter = SkillPokemon.begin();
	std::list<APokemon*>::iterator EndIter = SkillPokemon.end();
	if (StartIter == EndIter) {
		CurTurn = TurnType::Player_Select;
		return;
	}
	//	AI_Skill에 입장하면 포켓몬들이 동시에 공격하는게 아니라 SKillPokemon에 들어있는대로 순서대로 공격
	APokemon* CurPokemon = *StartIter;
	USkillController* CurAISkill = CurPokemon->GetSkillController();
	// 랜덤으로 타겟포켓몬 정하기
	if (CurAISkill->GetTargetPokemon() == nullptr) {
		std::vector<APokemon*>& TargetablePokemons = CurAISkill->GetTargetablePokemons();
		size_t TargetableSize = TargetablePokemons.size();
		UEngineRandom Random;
		int TargetIndex = Random.RandomInt(0, TargetableSize - 1);
		APokemon* TargetPokemon = TargetablePokemons[TargetIndex];
		FIntPoint TargetTile = TargetPokemon->GetTile();
		FIntPoint CurTile = CurPokemon->GetTile();
		FIntPoint TargetDir = TargetTile - CurTile;
		CurPokemon->SetDir(UContentsMath::FIntPoint_To_DIR(TargetDir));
		CurAISkill->SetTargetPokemon(TargetPokemon);
	}
	if (CurPokemon != nullptr) {
		CurPokemon->Skill(SkillType::NormalAttack);
	}
	if (true == CurPokemon->IsAttack()) {
		return;
	}
	//	공격끝나면 타겟포켓몬이 죽었는지 확인
	APokemon* TargetPokemon = CurAISkill->GetTargetPokemon();
	if (true == TargetPokemon->GetCurAbility()->IsDie()) {
		AllAIPokemon.remove(TargetPokemon);
		SkillPokemon.remove(TargetPokemon);
		MovePokemon.remove(TargetPokemon);
		CampType CurPokemonCamp = CurPokemon->GetCamp();
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		CompareCamp.remove(TargetPokemon);
		TargetPokemon->Destroy();
	}
	CurAISkill->SetTargetPokemon(nullptr);
	SkillPokemon.remove(CurPokemon);
	return;
}