#include "PreCompile.h"
#include "TurnManager.h"
#include "Player.h"

void ATurnManager::SelectSkill(int _PlayerInput)
{
	switch (_PlayerInput)
	{
	case'A':
		Player->SetCurSkillType(SkillType::NormalAttack);
		DIR PlayerDir = Player->GetCurDir();
		switch (PlayerDir)
		{
		case DIR::Left_Down:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::LEFT * 72 + FVector2D::DOWN * 72);
			break;
		case DIR::Down:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::DOWN * 72);
			break;
		case DIR::Right_Down:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::RIGHT * 72 + FVector2D::DOWN * 72);
			break;
		case DIR::Left:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::LEFT * 72);
			break;
		case DIR::Right:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::RIGHT * 72);
			break;
		case DIR::Left_Up:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::LEFT * 72 + FVector2D::UP * 72);
			break;
		case DIR::Up:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::UP * 72);
			break;
		case DIR::Right_Up:
			Player->SetTargetLocation(Player->GetActorLocation() + FVector2D::RIGHT * 72 + FVector2D::UP * 72);
			break;
		default:
			break;
		}

		//	여기 다시 짜야댐
		std::list<APokemon*>::iterator StartIter = AllPokemon.begin();
		std::list<APokemon*>::iterator EndIter = AllPokemon.end();
		for (;StartIter!=EndIter; StartIter++)
		{
			APokemon* EnemyPokemon = *StartIter;
			if (EnemyPokemon->GetActorLocation() == Player->GetTargetLocation()) {
				Player->SetTargetPokemon(EnemyPokemon);
			}
		}
	}
	CurTurnType = TurnType::Player_Skill;
}