#include "PreCompile.h"
#include "TurnManager.h"
#include "SkillManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	//	�Ϲݰ����� ����������
	if (PlayerInput == 'A') {
		Player->SetSkillType(SkillType::NormalAttack);
	}
	else if (PlayerInput == 'S') {
		if (Player->GetCurSpecialSkillName() == "") {
			CurTurn = TurnType::Player_Select;
			return;
		}
		Player->SetSkillType(SkillType::SpecialAttack);
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