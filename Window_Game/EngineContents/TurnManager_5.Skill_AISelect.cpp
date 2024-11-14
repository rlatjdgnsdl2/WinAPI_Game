#include "PreCompile.h"
#include "TurnManager.h"

#include "Pokemon.h"
#include "Player.h"

bool SortFuncD(APokemon* first, APokemon* second) {
	if (first->GetPokemonStat().Speed > second->GetPokemonStat().Speed)
	{
		return true;
	}
	return false;
}

void ATurnManager::Skill_AISelect()
{
	// speed�� ����
	AllAIPokemon.sort(SortFuncD);
	PlayerCamp.sort(SortFuncD);
	EnemyCamp.sort(SortFuncD);
	{
		//	��� AI���ϸ��
		std::list<APokemon*>::iterator StartIter = AllAIPokemon.begin();
		std::list<APokemon*> ::iterator EndIter = AllAIPokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			bool IsFindTarget = false;
			APokemon* CurPokemon = *StartIter;
			CurPokemon->ResetCurDuration();
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
					CurPokemon->StartAttack();
					SkillPokemon.push_back(CurPokemon);
					//	Ÿ���� ã�����ϱ� for�� ������
					IsFindTarget = true;
					break;
				}
			}
			//	��ó�� ���� ���ٸ�
			if (false == IsFindTarget) {
				//	�÷��̾ ������ �ϴ� ��ġŸ��
				FIntPoint PlayerTile = Player->GetTargetTile();
				FIntPoint CurTile = CurPokemon->GetCurTile();
				//	Astar�� ��ã��
				std::list<FIntPoint> PathForPlayer = PathFinder.PathFind(CurTile, PlayerTile);
				std::list<FIntPoint>::iterator Path = PathForPlayer.begin();
				std::list<FIntPoint>::iterator PathEnd = PathForPlayer.end();
				
				if (Path != PathEnd) {

					CurPokemon->SetStartLocation(*Path);
					Path++;
					if (Path == PathEnd) {
						Path = PathForPlayer.begin();
					}
					CurPokemon->SetTargetLocation(*Path);
					MovePokemon.push_back(CurPokemon);
				}

			}
		}

	}
	{
		// ����üũ - ���μ��� �Ȱ�ġ�� ����
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*> ::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			bool IsStand = false;
			APokemon* CurPokemon = *StartIter;
			//	���� Ÿ�ٷ����̼�
			FIntPoint CurTarget = CurPokemon->GetTargetTile();
			//	MovePokemon�� �ڽź��� ���ǵ� �������ϸ��̶� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
			std::vector<APokemon*>::iterator CompareIter = MovePokemon.begin();
			for (; CompareIter != StartIter; CompareIter++)
			{
				APokemon* ComparePokemon = *CompareIter;
				//	������ ���� ���ϸ��� Ÿ�ٷ����̼�
				FIntPoint CompareTarget = ComparePokemon->GetTargetTile();
				//	������ ���� ���ϸ��̶� �����̼� ��ġ��
				if (CurTarget == CompareTarget) {
					//	���ڸ�����
					CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
					IsStand = true;
					break;
				}
			}

			//	���� ���ǿ� �Ȱɷȴٸ�
			if (IsStand == false) {
				//	SkillPokemon�� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
				std::vector<APokemon*>::iterator StartIter = SkillPokemon.begin();
				std::vector<APokemon*> ::iterator EndIter = SkillPokemon.end();
				for (; StartIter != EndIter; StartIter++)
				{
					APokemon* ComparePokemon = *StartIter;
					FIntPoint CompareTarget = ComparePokemon->GetCurTile();
					if (CurTarget == CompareTarget) {
						CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
						break;
					}
				}
			}
			//	�������ٸ� ���⼳��
			FVector2D Dir = (CurPokemon->GetTargetLocation() - CurPokemon->GetStartLocation()) / 72.0f;
			if (Dir != FVector2D::ZERO) {
				CurPokemon->SetCurDir(UContentsMath::FVector2D_To_DIR(Dir));
			}
		}
	}
	CurTurnType = TurnType::AI_Move;
	return;
}