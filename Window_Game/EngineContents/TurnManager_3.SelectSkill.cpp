#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	//	�Ϲݰ����� ����������
	if (PlayerInput == 'A') {
		Player->SetCurSkillType(SkillType::NormalAttack);
		DIR CurPlayerDir = Player->GetCurDir();
		FVector2D Dir = UContentsMath::DIR_To_Vector2D(CurPlayerDir);
		FIntPoint TargetTile = Player->GetCurTile() + Dir.ConvertToPoint();

		//	�ڽ��� ������ ���⿡ �����ϸ��� �ִ��� Ȯ��
		for (APokemon* CurCheckPokemon : EnemyCamp)
		{
			FIntPoint CheckPokemonTile = CurCheckPokemon->GetCurTile();
			if (TargetTile == CheckPokemonTile) {
				//	������ Ÿ�����ϸ����� ����
				Player->SetTargetPokemon(CurCheckPokemon);
				break;
			}
		}
	}
	Player->StartAttack();
	CurTurnType = TurnType::Player_Skill;
	return;
}