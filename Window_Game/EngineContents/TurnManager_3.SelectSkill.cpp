#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "SkillController.h"
void ATurnManager::SelectSkill()
{
	USkillController* PlayerSkill = Player->GetSkillController();
	//	�Ϲݰ����� ����������
	if (PlayerInput == 'A') {
		DIR CurPlayerDir = Player->GetDir();
		FVector2D Dir = UContentsMath::DIR_To_Vector2D(CurPlayerDir);
		FIntPoint TargetTile = Player->GetTile() + Dir.ConvertToPoint();
		//	�ڽ��� ������ ���⿡ �����ϸ��� �ִ��� Ȯ��
		for (APokemon* CurCheckPokemon : EnemyCamp){
			FIntPoint CheckPokemonTile = CurCheckPokemon->GetTile();
			if (TargetTile == CheckPokemonTile) {
				//	������ Ÿ�����ϸ����� ����
				PlayerSkill->SetTargetPokemon(CurCheckPokemon);
				break;
			}
		}
	}
	Player->StartAttack();
	CurTurn = TurnType::Player_Skill;
	return;
}