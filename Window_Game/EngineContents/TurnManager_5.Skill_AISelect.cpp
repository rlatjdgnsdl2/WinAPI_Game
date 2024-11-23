#include "PreCompile.h"
#include "TurnManager.h"

#include "Pokemon.h"
#include "Player.h"



bool SortFuncD(APokemon* first, APokemon* second) {
	return first->GetSPD() > second->GetSPD();
}

void ATurnManager::Skill_AISelect()
{
	// speed�� ����
	AllAIPokemon.sort(SortFuncD);
	PlayerCamp.sort(SortFuncD);
	EnemyCamp.sort(SortFuncD);

	//	��� AI���ϸ��
	for (APokemon* CurPokemon : AllAIPokemon) {
		bool IsFindTarget = false;
		CurPokemon->ResetCurDuration();
		FIntPoint CurTile = CurPokemon->GetTile();
		CampType CurPokemonCamp = CurPokemon->GetCamp();
		//	�ݴ����� ����Ʈ������
		std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
		// Ÿ�Ϸ����̼� Ȯ��
		for (APokemon* CurComparePokemon : CompareCamp) {
			FIntPoint Distance = CurComparePokemon->GetTargetTile() - CurTile;
			//	��ó�� ���� �ִٸ� ��ų����Ʈ
			if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
				IsFindTarget = true;
				CurPokemon->PushTargetablePokemon(CurComparePokemon);
				//	�ִϸ��̼� ù �����ӿ� ���ε尡 �� �����ʾ� ���� - ���� ����
				CurPokemon->StartAttack();
				SkillPokemon.push_back(CurPokemon);
				break;
			}
		}
		//	��ó�� ���� ���ٸ� ���긮��Ʈ
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

	// ����üũ - ���μ��� �Ȱ�ġ�� ����
	for (APokemon* CurPokemon : MovePokemon)
	{
		bool IsStand = false;
		FIntPoint CurTarget = CurPokemon->GetTargetTile();

		// ���긮��Ʈ �� �ڽź��� ���ǵ� ���� ���ϸ��̶� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
		for (APokemon* ComparePokemon : MovePokemon)
		{
			if (ComparePokemon == CurPokemon) { break; }
			if (CurTarget == ComparePokemon->GetTargetTile()) {
				CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
				IsStand = true;
				break;
			}
		}
		// ���� ���ǿ� �Ȱɷȴٸ� ��ų����Ʈ �� ��ġ���� Ȯ��
		if (!IsStand) {
			for (APokemon* ComparePokemon : SkillPokemon) {
				if (CurTarget == ComparePokemon->GetTile()) {
					CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
					break;
				}
			}
		}

		// �������ٸ� ���⼳��
		FVector2D CurTargetLocation = CurPokemon->GetTargetLocation();
		FVector2D CurLocation = CurPokemon->GetActorLocation();
		FVector2D DirVec = (CurTargetLocation - CurLocation) / 72.0f;
		if (DirVec != FVector2D::ZERO) {
			DIR Dir = UContentsMath::FVector2D_To_DIR(DirVec);
			CurPokemon->SetDir(Dir);
		}
	}


	CurTurn = TurnType::AI_Move;
	return;
}