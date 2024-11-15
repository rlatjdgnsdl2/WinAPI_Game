#include "PreCompile.h"
#include "TurnManager.h"

#include "Pokemon.h"
#include "Player.h"

bool SortFuncD(APokemon* first, APokemon* second) {
	return first->GetCurAbility().GetSpeed() > second->GetCurAbility().GetSpeed();
}

void ATurnManager::Skill_AISelect()
{
	// speed�� ����
	AllAIPokemon.sort(SortFuncD);
	PlayerCamp.sort(SortFuncD);
	EnemyCamp.sort(SortFuncD);
	{
		//	��� AI���ϸ��
		for (APokemon* CurPokemon : AllAIPokemon)
		{
			bool IsFindTarget = false;
			CurPokemon->ResetCurDuration();
			FIntPoint CurTile = CurPokemon->GetTile();
			CampType CurPokemonCamp = CurPokemon->GetCamp();
			//	�ݴ����� ����Ʈ������
			std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
			// Ÿ�Ϸ����̼� Ȯ��
			for (APokemon* CurComparePokemon : CompareCamp)
			{
				FIntPoint Distance = CurComparePokemon->GetTargetTile() - CurTile;
				//	��ó�� ���� �ִٸ�
				if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
					CurPokemon->StartAttack();
					SkillPokemon.push_back(CurPokemon);
					IsFindTarget = true;
					break;
				}
			}
			//	��ó�� ���� ���ٸ�
			if (false == IsFindTarget) {
				//	�÷��̾ ���� ��ã��
				FIntPoint PlayerTile = Player->GetTargetTile();
				std::list<FIntPoint> PathForPlayer = PathFinder.PathFind(CurTile, PlayerTile);
				if (!PathForPlayer.empty()) {
					auto Path = PathForPlayer.begin();
					if (++Path == PathForPlayer.end()) {
						Path = PathForPlayer.begin();
					}
					CurPokemon->SetTargetTile(*Path);
					MovePokemon.push_back(CurPokemon);
				}
			}
		}
	}


	{
		// ����üũ - ���μ��� �Ȱ�ġ�� ����
		for (APokemon* CurPokemon : MovePokemon)
		{
			bool IsStand = false;
			//	���� Ÿ�ٷ����̼�
			FIntPoint CurTarget = CurPokemon->GetTargetTile();
			//	MovePokemon�� �ڽź��� ���ǵ� �������ϸ��̶� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
			std::vector<APokemon*>::iterator CompareIter = MovePokemon.begin();
			for (; *CompareIter != CurPokemon; CompareIter++)
			{
				APokemon* ComparePokemon = *CompareIter;
				//	������ ���� ���ϸ��� Ÿ�ٷ����̼�
				FIntPoint CompareTarget = ComparePokemon->GetTargetTile();
				//	������ ���� ���ϸ��̶� �����̼� ��ġ��
				if (CurTarget == CompareTarget) {
					//	���ڸ�����
					CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
					IsStand = true;
					break;
				}
			}
			//	���� ���ǿ� �Ȱɷȴٸ�
			if (!IsStand) {
				for (APokemon* ComparePokemon : SkillPokemon) {
					if (CurTarget == ComparePokemon->GetTile()) {
						CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
						break;
					}
				}
			}
			//	�������ٸ� ���⼳��
			FVector2D Dir = (CurPokemon->GetTargetLocation() - CurPokemon->GetActorLocation()) / 72.0f;
			if (Dir != FVector2D::ZERO) {
				CurPokemon->SetDir(UContentsMath::FVector2D_To_DIR(Dir));
			}
		}
	}

	CurTurnType = TurnType::AI_Move;
	return;
}