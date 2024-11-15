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
	//	AI_Skill�� �����ϸ� ���ϸ���� ���ÿ� �����ϴ°� �ƴ϶� SKillPokemon�� ����ִ´�� ������� ����
	APokemon* CurPokemon = SkillPokemon[GCurIndex];
	// Ÿ�����ϸ� ���ϱ�
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
	CurPokemon->Skill();
	if (true == CurPokemon->IsAttack()) {
		return;
	}
	GCurIndex++;
	return;
}