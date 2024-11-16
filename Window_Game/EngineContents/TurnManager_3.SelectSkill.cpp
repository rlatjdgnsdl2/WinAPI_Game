#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "SkillController.h"
void ATurnManager::SelectSkill()
{
	USkillController* PlayerSkill = Player->GetSkillController();
	//	일반공격을 선택했으면
	if (PlayerInput == 'A') {
		DIR CurPlayerDir = Player->GetDir();
		FVector2D Dir = UContentsMath::DIR_To_Vector2D(CurPlayerDir);
		FIntPoint TargetTile = Player->GetTile() + Dir.ConvertToPoint();
		//	자신이 공격한 방향에 적포켓몬이 있는지 확인
		for (APokemon* CurCheckPokemon : EnemyCamp){
			FIntPoint CheckPokemonTile = CurCheckPokemon->GetTile();
			if (TargetTile == CheckPokemonTile) {
				//	있으면 타겟포켓몬으로 지정
				PlayerSkill->SetTargetPokemon(CurCheckPokemon);
				break;
			}
		}
	}
	Player->StartAttack();
	CurTurn = TurnType::Player_Skill;
	return;
}