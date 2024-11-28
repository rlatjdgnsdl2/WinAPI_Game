#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"

void ATurnManager::SelectSkill()
{
	//	�Ϲݰ����� ����������
	if (PlayerInput == 'A') {
		Player->SetSkill(SkillType::NormalAttack);	
	}

	else if (PlayerInput == 'S') {
		if (Player->GetCurSpecialSkillName() == "") {
			CurTurn = TurnType::Player_Select;
			return;
		}
	}

	DIR CurPlayerDir = Player->GetDir();
	FVector2D Dir = UContentsMath::DIR_To_FVector2D(CurPlayerDir);
	FIntPoint TargetTile = Player->GetTile() + Dir.ConvertToPoint();
	//	�ڽ��� ������ ���⿡ �����ϸ��� �ִ��� Ȯ��
	for (APokemon* CurCheckPokemon : EnemyCamp) {
		FIntPoint CheckPokemonTile = CurCheckPokemon->GetTile();
		if (TargetTile == CheckPokemonTile) {
			//	������ Ÿ�����ϸ����� ����
			Player->SetTargetPokemon(CurCheckPokemon);
			break;
		}
	}
	//	��ų�� ����������
	CurTurn = TurnType::Player_Skill_Start;
	return;
}