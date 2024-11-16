#include "PreCompile.h"
#include "TurnManager.h"


#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"
#include "MoveController.h"
#include "SkillController.h"
#include "AbilityController.h"

// ���ǵ� ������ ����
bool SortFunc(APokemon* first, APokemon* second) {
	return first->GetCurAbility()->GetSpeed() > second->GetCurAbility()->GetSpeed();
}


void ATurnManager::Move_AISelect()
{
	// speed�� ����
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);
	UMoveController* PlayerMove = Player->GetMoveController();
	{
		//	��� AI���ϸ��
		for (APokemon* CurPokemon : AllAIPokemon){
			UMoveController* CurAIMove = CurPokemon->GetMoveController();
			USkillController* CurAISkill = CurPokemon->GetSkillController();
			bool IsFindTarget = false;
			CurAIMove->ResetCurDuration();
			FIntPoint CurTile = CurAIMove->GetTile();
			CampType CurPokemonCamp = CurPokemon->GetCamp();
			//	�÷��̾����϶� �÷��̾ �������� �´ٸ� ���긮��Ʈ, �÷��̾�� �ڸ� �ٲٱ�
			if (CurPokemonCamp == CampType::Player && PlayerMove->GetTargetTile() == CurTile) {
				CurAIMove->SetTargetLocation(Player->GetActorLocation());
				MovePokemon.push_back(CurPokemon);
				continue;
			}
			//	�ݴ����� ����Ʈ������
			std::list<APokemon*>& CompareCamp = (CurPokemonCamp == CampType::Player) ? EnemyCamp : PlayerCamp;
			// Ÿ�Ϸ����̼� Ȯ��
			for (APokemon* CurComparePokemon : CompareCamp){
				FIntPoint Distance = CurComparePokemon->GetMoveController()->GetTargetTile() - CurTile;
				//	��ó�� ���� �ִٸ� ��ų����Ʈ
				if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
					IsFindTarget = true;
					CurAISkill->PushTargetablePokemon(CurComparePokemon);
					//	�ִϸ��̼� ù �����ӿ� ���ε尡 �� �����ʾ� ���� - ���� ����
					CurPokemon->StartAttack();
					SkillPokemon.push_back(CurPokemon);
					break;
				}
			}
			//	��ó�� ���� ���ٸ� ���긮��Ʈ
			if (false == IsFindTarget) {
				//	�÷��̾ ���� ��ã��
				FIntPoint PlayerTile = PlayerMove->GetTargetTile();
				std::list<FIntPoint> PathForPlayer = PathFinder.PathFind(CurTile, PlayerTile);
				if (!PathForPlayer.empty()) {
					auto Path = PathForPlayer.begin();
					if (++Path == PathForPlayer.end()) {
						Path = PathForPlayer.begin();
					}
					CurAIMove->SetTargetTile(*Path);
					MovePokemon.push_back(CurPokemon);
				}
			}
		}

	}

	{
		// ����üũ - ���μ��� �Ȱ�ġ�� ����
		for (APokemon* CurPokemon : MovePokemon)
		{
			UMoveController* CurAIMove = CurPokemon->GetMoveController();
			bool IsStand = false;
			FIntPoint CurTarget = CurAIMove->GetTargetTile();

			// ���긮��Ʈ �� �ڽź��� ���ǵ� ���� ���ϸ��̶� Ÿ�ٷ����̼� ��ġ�� ���ڸ�
			for (APokemon* ComparePokemon : MovePokemon)
			{
				if (ComparePokemon == CurPokemon) break;
				if (CurTarget == ComparePokemon->GetMoveController()->GetTargetTile()) {
					CurAIMove->SetTargetLocation(CurPokemon->GetActorLocation());
					IsStand = true;
					break;
				}
			}
			// ���� ���ǿ� �Ȱɷȴٸ� ��ų����Ʈ �� ��ġ���� Ȯ��
			if (!IsStand) {
				for (APokemon* ComparePokemon : SkillPokemon) {
					if (CurTarget == ComparePokemon->GetMoveController()->GetTile()) {
						CurAIMove->SetTargetLocation(CurPokemon->GetActorLocation());
						break;
					}
				}
			}

			// �������ٸ� ���⼳��
			FVector2D Dir = (CurAIMove->GetTargetLocation() - CurPokemon->GetActorLocation()) / 72.0f;
			if (Dir != FVector2D::ZERO) {
				CurPokemon->SetDir(UContentsMath::FVector2D_To_DIR(Dir));
			}
		}
	}
	// �����ܰ�
	CurTurn = TurnType::Player_Move;
	return;
}

