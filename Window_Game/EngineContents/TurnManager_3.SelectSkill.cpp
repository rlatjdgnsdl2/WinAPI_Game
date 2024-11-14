#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	//	일반공격을 선택했으면
	if (PlayerInput == 'A') {
		Player->SetCurSkillType(SkillType::NormalAttack);
		DIR CurPlayerDir = Player->GetCurDir();
		FVector2D Dir = UContentsMath::DIR_To_Vector2D(CurPlayerDir);
		FIntPoint TargetTile = Player->GetCurTile() + Dir.ConvertToPoint();

		//	자신이 공격한 방향에 적포켓몬이 있는지 확인
		std::list<APokemon*>::iterator EnemyStartIter = EnemyCamp.begin();
		std::list<APokemon*>::iterator EnemyEndIter = EnemyCamp.end();
		for (; EnemyStartIter != EnemyEndIter; EnemyStartIter++)
		{
			APokemon* CurCheckPokemon = *EnemyStartIter;
			FIntPoint CheckPokemonTile = CurCheckPokemon->GetCurTile();
			if (TargetTile == CheckPokemonTile) {
				Player->SetTargetPokemon(CurCheckPokemon);
				break;
			}
		}
	}
	Player->StartAttack();
	CurTurnType = TurnType::Player_Skill;
	return;
}