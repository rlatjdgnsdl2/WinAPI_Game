#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "SkillController.h"
void ATurnManager::SelectSkill()
{
	USkillController* PlayerSkill = Player->GetSkillController();
	if (PlayerSkill == nullptr) {
		CurTurn = TurnType::Player_Select;
		return;
	}
	//	�Ϲݰ����� ����������
	if (PlayerInput == 'A') {
		PlayerSkill->SetSkill(SkillType::NormalAttack);
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

	//	��ų�� ����������
	else if (PlayerInput == 'S') {
		PlayerSkill->SetSkill(SkillType::SpecialAttack);
	}
	//	�����ۻ���� ����������
	else if (PlayerInput == 'D') {
		PlayerSkill->SetSkill(SkillType::UseItem);
	}

	//	�ӽ��ڵ�
	Player->StartAttack();
	CurTurn = TurnType::Player_Skill;
	return;
}