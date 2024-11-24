#include "PreCompile.h"
#include "TurnManager.h"

#include <EngineBase/EngineRandom.h>
#include "Pokemon.h"
#include "Partner.h"
#include "DungeonUI.h"

void ATurnManager::AISkillStart()
{
	if (SkillPokemon.empty()) {
		ResetTurn();
		return;
	}
	APokemon* CurPokemon = SkillPokemon.front();
	// 랜덤으로 타겟포켓몬 정하기
	if (CurPokemon->GetTargetPokemon() == nullptr) {
		SelectRandomTarget(CurPokemon);
	}
	APokemon* TargetPokemon = CurPokemon->GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		int Damage = UContentsMath::DamageCalculation(CurPokemon->GetATK(), TargetPokemon->GetDEF());
		DungeonUI->NewLogMessage(
			{ CurPokemon->GetName()," damage to ", TargetPokemon->GetName()," for " ,std::to_string(Damage) },
			{ Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow });
		TargetPokemon->SetDamage(Damage);
	}
	CurTurn = TurnType::AI_Skill;
}

void ATurnManager::AISkill()
{
	if (SkillPokemon.empty()) {
		ResetTurn();
		return;
	}
	APokemon* CurPokemon = SkillPokemon.front();
	if (CurPokemon != nullptr) {
		CurPokemon->Skill();
	}
	if (CurPokemon->IsAttack()) {
		return;
	}
	CurTurn = TurnType::AI_Skill_End;
}

void ATurnManager::AISkillEnd()
{
	if (SkillPokemon.empty()) {
		ResetTurn();
		return;
	}
	APokemon* CurPokemon = SkillPokemon.front();
	APokemon* TargetPokemon = CurPokemon->GetTargetPokemon();
	if (TargetPokemon != nullptr && TargetPokemon->IsDie()) {
		HandleTargetDeath(CurPokemon, TargetPokemon);
	}
	CurPokemon->SetTargetPokemon(nullptr);
	SkillPokemon.remove(CurPokemon);
	CurTurn = TurnType::AI_Skill_Start;
}





void ATurnManager::ResetTurn()
{
	CurDuration = 0.0f;
	CurTurn = TurnType::Player_Select;
}

void ATurnManager::SelectRandomTarget(APokemon* CurPokemon)
{
	std::vector<APokemon*>& TargetablePokemons = CurPokemon->GetTargetablePokemons();
	int TargetableSize = static_cast<int>(TargetablePokemons.size());
	if (TargetableSize == 0) {
		return; // 타겟 가능한 포켓몬이 없으면 리턴
	}
	UEngineRandom Random;
	int TargetIndex = Random.RandomInt(0, TargetableSize - 1);
	APokemon* TargetPokemon = TargetablePokemons[TargetIndex];
	if (TargetPokemon == nullptr) {
		return; // 타겟 포켓몬이 nullptr이면 리턴
	}
	FIntPoint TargetTile = TargetPokemon->GetTile();
	FIntPoint CurTile = CurPokemon->GetTile();
	FIntPoint TargetDir = TargetTile - CurTile;

	CurPokemon->SetDir(UContentsMath::FIntPoint_To_DIR(TargetDir));
	CurPokemon->SetTargetPokemon(TargetPokemon);
	CurPokemon->SetSkill(SkillType::NormalAttack);
	CurPokemon->ResetTargetablePokemon();
}

void ATurnManager::HandleTargetDeath(APokemon* CurPokemon, APokemon* TargetPokemon)
{
	if (TargetPokemon->GetCamp() == CampType::Player) {
		// 게임오버
	}
	else {
		int Level = TargetPokemon->GetLevel();
		DungeonUI->NewLogMessage(
			{ TargetPokemon->GetName()," Die and ", "Player Party",  " Gain EXP ",std::to_string(TargetPokemon->GetLevel() * 100) }, { Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow });
		// 파티원 전원 경험치 획득 후 레벨업했으면
		for (APokemon* CurPokemon : PlayerCamp) {
			if (CurPokemon != nullptr && CurPokemon->GainExp(TargetPokemon->GetLevel() * 100)) {
				DungeonUI->NewLogMessage(
					{ CurPokemon->GetName()," Level Up!", }, { Color::Blue,Color::Yellow });
				DungeonUI->NewLogMessage(
					{ "All Ability ","+2" }, { Color::White,Color::Yellow });
			}
		}
		RemovePokemonFromLists(TargetPokemon);
		TargetPokemon->Destroy();
	}
}

void ATurnManager::RemovePokemonFromLists(APokemon* TargetPokemon)
{
	AllAIPokemon.remove(TargetPokemon);
	SkillPokemon.remove(TargetPokemon);
	MovePokemon.remove(TargetPokemon);
	CampType CurPokemonCamp = TargetPokemon->GetCamp();
	std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
	CompareCamp.remove(TargetPokemon);
}