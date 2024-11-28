#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"
#include "Dungeon_BSP.h"

void ATurnManager::SelectSkill()
{
	//	일반공격을 선택했으면
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
	//	자신이 공격할 방향에 적포켓몬이 있는지 확인
	for (APokemon* CurCheckPokemon : EnemyCamp) {
		FIntPoint CheckPokemonTile = CurCheckPokemon->GetTile();
		if (TargetTile == CheckPokemonTile) {
			//	있으면 타겟포켓몬으로 지정
			Player->SetTargetPokemon(CurCheckPokemon);
			break;
		}
	}
	//	스킬을 선택했으면
	CurTurn = TurnType::Player_Skill_Start;
	return;
}