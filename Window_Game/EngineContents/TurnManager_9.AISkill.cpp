#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineBase/EngineRandom.h>
#include "Pokemon.h"
#include "AbilityController.h"




void ATurnManager::AISkill()
{
	int MaxIndex = static_cast<int>(SkillPokemon.size());
	std::list<APokemon*>::iterator StartIter = SkillPokemon.begin();
	std::list<APokemon*>::iterator EndIter = SkillPokemon.end();
	if (StartIter == EndIter) {
		CurTurn = TurnType::Player_Select;
		return;
	}
	//	AI_Skill�� �����ϸ� ���ϸ���� ���ÿ� �����ϴ°� �ƴ϶� SKillPokemon�� ����ִ´�� ������� ����
	APokemon* CurPokemon = *StartIter;
	// �������� Ÿ�����ϸ� ���ϱ�
	if (CurPokemon->GetTargetPokemon() == nullptr) {
		std::vector<APokemon*>& TargetablePokemons = CurPokemon->GetTargetablePokemons();
		int TargetableSize = static_cast<int>(TargetablePokemons.size());
		UEngineRandom Random;
		int TargetIndex = Random.RandomInt(0, TargetableSize - 1);
		APokemon* TargetPokemon = TargetablePokemons[TargetIndex];
		FIntPoint TargetTile = TargetPokemon->GetTile();
		FIntPoint CurTile = CurPokemon->GetTile();
		FIntPoint TargetDir = TargetTile - CurTile;

		CurPokemon->SetDir(UContentsMath::FIntPoint_To_DIR(TargetDir));
		CurPokemon->SetTargetPokemon(TargetPokemon);
		CurPokemon->SetSkill(SkillType::NormalAttack);
	}
	if (CurPokemon != nullptr) {
		CurPokemon->Skill();
	}
	if (true == CurPokemon->IsAttack()) {
		return;
	}
	//	���ݳ����� Ÿ�����ϸ��� �׾����� Ȯ��
	APokemon* TargetPokemon = CurPokemon->GetTargetPokemon();
	if (TargetPokemon != nullptr) {

		if (true == TargetPokemon->GetCurAbility()->IsDie()) {
			AllAIPokemon.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			CampType CurPokemonCamp = CurPokemon->GetCamp();
			std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
			CompareCamp.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	CurPokemon->SetTargetPokemon(nullptr);
	SkillPokemon.remove(CurPokemon);
	return;
}