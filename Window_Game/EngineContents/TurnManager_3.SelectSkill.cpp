#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	//	�Ϲݰ����� ����������
	if (PlayerInput == 'A') {
		Player->SetSkillType(SkillType::NormalAttack);
		DIR CurPlayerDir = Player->GetDir();
		FVector2D Dir = UContentsMath::DIR_To_Vector2D(CurPlayerDir);
		FIntPoint TargetTile = Player->GetTile() + Dir.ConvertToPoint();

		//	�ڽ��� ������ ���⿡ �����ϸ��� �ִ��� Ȯ��
		for (APokemon* CurCheckPokemon : EnemyCamp)
		{
			FIntPoint CheckPokemonTile = CurCheckPokemon->GetTile();
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