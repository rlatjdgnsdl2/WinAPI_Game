#include "PreCompile.h"
#include "TurnManager.h"

#include <EnginePlatform/EngineInput.h>

#include "Dungeon.h"
#include "Player.h"
#include "Partner.h"


void ATurnManager::PlayerIdle()
{
	CurDuration = 0.0f;
	Player->Idle();
	Partner->Idle();
	
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD8))
	{
		Player->SetDir(DIR::Up);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::UP * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD7))
	{
		Player->SetDir(DIR::Left_Up);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::UP * 72)+ (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD4))
	{
		Player->SetDir(DIR::Left);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD1))
	{
		Player->SetDir(DIR::Left_Down);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::DOWN * 72) + (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD2))
	{
		Player->SetDir(DIR::Down);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::DOWN * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD3))
	{
		Player->SetDir(DIR::Right_Down);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::DOWN * 72) + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD6))
	{
		Player->SetDir(DIR::Right);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD9))
	{
		Player->SetDir(DIR::Right_Up);
		FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + (FVector2D::UP * 72) + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation = StartLocation;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	Partner->SetStartLocation(Partner->GetActorLocation());
	FVector2D PartnerTargetLocation = Partner->SetTargetLocation(Player->GetStartLocation());

}