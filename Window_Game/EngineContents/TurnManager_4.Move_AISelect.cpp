#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"


bool SortFunc(APokemon* first, APokemon* second) {
	if (first->GetPokemonStat().Speed > second->GetPokemonStat().Speed)
	{
		return true;
	}
	return false;
}


void ATurnManager::Move_AISelect(float _DeltaTime)
{
	// speed�� ����
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);
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
			//	���� ����
			CampType CurPokemonCamp = CurPokemon->GetCurCamp();
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
					CurPokemon->SetTargetPokemon(CurComparePokemon);
					CurPokemon->SetCurSkillType(SkillType::NormalAttack);
					SkillPokemon.push_back(CurPokemon);
					IsFindTarget = true;
					break;
				}
			}
			//	��ó�� ���� ���ٸ�
			if (false == IsFindTarget) {
				FIntPoint PlayerTile = Player->GetTargetTile();
				FIntPoint CurTile = CurPokemon->GetCurTile();
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
		// ����üũ
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*> ::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			std::vector<APokemon*>::iterator CompareIter = MovePokemon.begin();
			//	MovePokemon�� �ڽź��� ���ǵ� �������ϸ��̶� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
			for (; CompareIter != StartIter; CompareIter++)
			{
				APokemon* ComparePokemon = *CompareIter;
				FIntPoint CurTarget = CurPokemon->GetTargetTile();
				FIntPoint CompareTarget = ComparePokemon->GetTargetTile();
				if (CurTarget == CompareTarget) {
					CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
					break;
				}
			}
			//	SkillPokemon�� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
			std::vector<APokemon*>::iterator SkillStartIter = SkillPokemon.begin();
			std::vector<APokemon*> ::iterator SkillEndIter = SkillPokemon.end();
			for (; SkillStartIter != SkillEndIter; SkillStartIter++)
			{
				APokemon* ComparePokemon = *SkillStartIter;
				FIntPoint CurTarget = CurPokemon->GetTargetTile();
				FIntPoint CompareTarget = ComparePokemon->GetCurTile();
				if (CurTarget == CompareTarget) {
					CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation());
					break;
				}
			}
			//	�������ٸ� ���⼳��
			FVector2D Dir = (CurPokemon->GetTargetLocation() - CurPokemon->GetStartLocation()) / 72.0f;
			if (Dir == FVector2D::UP)
			{
				CurPokemon->SetCurDir(DIR::Up);
			}
			else if (Dir == FVector2D::DOWN)
			{
				CurPokemon->SetCurDir(DIR::Down);
			}
			else if (Dir == FVector2D::LEFT)
			{
				CurPokemon->SetCurDir(DIR::Left);
			}
			else if (Dir == FVector2D::RIGHT)
			{
				CurPokemon->SetCurDir(DIR::Right);
			}
			else if (Dir == FVector2D::UP + FVector2D::LEFT)
			{
				CurPokemon->SetCurDir(DIR::Left_Up);
			}
			else if (Dir == FVector2D::UP + FVector2D::RIGHT)
			{
				CurPokemon->SetCurDir(DIR::Right_Up);
			}
			else if (Dir == FVector2D::DOWN + FVector2D::LEFT)
			{
				CurPokemon->SetCurDir(DIR::Left_Down);
			}
			else if (Dir == FVector2D::DOWN + FVector2D::RIGHT)
			{
				CurPokemon->SetCurDir(DIR::Right_Down);
			}
		}

		// �����ܰ�
		CurTurnType = TurnType::Player_Move;
	}
}

