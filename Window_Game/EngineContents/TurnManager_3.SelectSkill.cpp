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
		FVector2D Dir;
		switch (CurPlayerDir)
		{
		case DIR::Left_Down:
			Dir = FVector2D::LEFT + FVector2D::DOWN;
			break;
		case DIR::Down:
			Dir = FVector2D::DOWN;
			break;
		case DIR::Right_Down:
			Dir = FVector2D::RIGHT + FVector2D::DOWN;
			break;
		case DIR::Left:
			Dir = FVector2D::LEFT;
			break;
		case DIR::Right:
			Dir = FVector2D::RIGHT;
			break;
		case DIR::Left_Up:
			Dir = FVector2D::LEFT + FVector2D::UP;
			break;
		case DIR::Up:
			Dir = FVector2D::UP;
			break;
		case DIR::Right_Up:
			Dir = FVector2D::RIGHT + FVector2D::UP;
			break;
		default:
			break;
		}
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