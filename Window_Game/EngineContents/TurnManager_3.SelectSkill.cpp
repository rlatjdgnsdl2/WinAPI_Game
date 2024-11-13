#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill()
{
	//	일반공격
	if (PlayerInput == 'A') {
		Player->SetCurSkillType(SkillType::NormalAttack);
		Player->StartAttack();
		DIR CurPlayerDir = Player->GetCurDir();
		FVector2D Dir = UContentsMath::DIR_To_Vector2D(CurPlayerDir);
		FIntPoint TargetTile = Player->GetCurTile() + Dir.ConvertToPoint();
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


	CurTurnType = TurnType::Player_Skill;
}