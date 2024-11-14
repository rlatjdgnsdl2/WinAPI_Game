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
	//	AI_Skill�� �����ϸ� ���ϸ���� ���ÿ� �����ϴ°� �ƴ϶� SKillPokemon�� ����ִ´�� ������� ����
	APokemon* CurPokemon = SkillPokemon[GCurIndex];
	//Ÿ�����ϸ� ���ϱ�
	if (CurPokemon->GetTargetPokemon() == nullptr) {
		//�ڱ� �ֺ� �Ѹ� �������� Target����
		FIntPoint CurTile = CurPokemon->GetCurTile();
		//	����üũ
		CampType CurPokemonCamp = CurPokemon->GetCurCamp();
		//	�ݴ����� ����Ʈ������
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		std::list<APokemon*> ::iterator CompareStartIter = CompareCamp.begin();
		std::list<APokemon*> ::iterator CompareEndIter = CompareCamp.end();
		// Ÿ�Ϸ����̼� Ȯ��
		for (; CompareStartIter != CompareEndIter; CompareStartIter++)
		{
			APokemon* CurComparePokemon = *CompareStartIter;
			FIntPoint CompareTargetTile = CurComparePokemon->GetTargetTile();
			FIntPoint Distance = CompareTargetTile - CurTile;
			//	��ó�� ���� �ִٸ�
			if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
				//	�ִϸ��̼� ���⼳��
				CurPokemon->SetCurDir(UContentsMath::FIntPoint_To_DIR(Distance));
				CurPokemon->SetCurSkillType(SkillType::NormalAttack);
				//	���߿� Ÿ�����ϸ� �������ؼ� �������� ����
				CurPokemon->SetTargetPokemon(CurComparePokemon);
				//	Ÿ���� ã�����ϱ� for�� ������
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