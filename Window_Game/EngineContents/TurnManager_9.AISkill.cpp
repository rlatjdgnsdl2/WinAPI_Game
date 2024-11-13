#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"

int CurIndex = 0;

void ATurnManager::AISkill()
{
	int MaxIndex = SkillPokemon.size();
	if (CurIndex != MaxIndex) {
		APokemon* CurPokemon = SkillPokemon[CurIndex];
		//Ÿ�����ϸ� ���ؾ���
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