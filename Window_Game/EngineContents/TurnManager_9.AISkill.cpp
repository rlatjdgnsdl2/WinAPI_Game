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
	//	AI_Skill�� �����ϸ� ���ϸ���� ���ÿ� �����ϴ°� �ƴ϶� SKillPokemon�� ����ִ´�� ������� ����
	APokemon* CurPokemon = *StartIter;
	USkillController* CurAISkill = CurPokemon->GetSkillController();
	// �������� Ÿ�����ϸ� ���ϱ�
	if (CurAISkill->GetTargetPokemon() == nullptr) {
		std::vector<APokemon*>& TargetablePokemons = CurAISkill->GetTargetablePokemons();
		
		
		
	}
	if (CurPokemon != nullptr) {
		CurPokemon->Skill(SkillType::NormalAttack);
	}
	if (true == CurPokemon->IsAttack()) {
		return;
	}
	//	���ݳ����� Ÿ�����ϸ��� �׾����� Ȯ��
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