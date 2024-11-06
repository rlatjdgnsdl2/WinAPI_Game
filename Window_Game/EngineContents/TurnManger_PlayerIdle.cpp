#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Dungeon.h"
#include "Player.h"


void ATurnManager::PlayerIdle()
{
	CurDuration = 0.0f;
	Player->GetSpriteRenderer()->ChangeAnimation("IdleAnim_" + std::to_string((int)Player->GetDir()));
	Player->GetSpriteRenderer()->SetSpriteScale();
	if (true == UEngineInput::GetInst().IsPress('W'))
	{
		Player->SetDir(DIR::Up);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::UP * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		/*if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress('A'))
	{
		Player->SetDir(DIR::Left);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		/*if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		Player->SetDir(DIR::Down);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::DOWN * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		/*if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress('D'))
	{
		Player->SetDir(DIR::Right);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		/*if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}*/
		CurTurnType = TurnType::PlayerMove;
	}

}