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
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::UP * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		


		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD7))
	{
		Player->SetDir(DIR::Left_Up);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::UP * 72)+ (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD4))
	{
		Player->SetDir(DIR::Left);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD1))
	{
		Player->SetDir(DIR::Left_Down);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::DOWN * 72) + (FVector2D::LEFT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD2))
	{
		Player->SetDir(DIR::Down);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::DOWN * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD3))
	{
		Player->SetDir(DIR::Right_Down);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::DOWN * 72) + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD6))
	{
		Player->SetDir(DIR::Right);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_NUMPAD9))
	{
		Player->SetDir(DIR::Right_Up);
		FVector2D StartLocation_Player = Player->SetStartLocation(Player->GetActorLocation());
		FVector2D TargetLocation_Player = Player->SetTargetLocation(StartLocation_Player + (FVector2D::UP * 72) + (FVector2D::RIGHT * 72));
		TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation_Player.iY() / 72][TargetLocation_Player.iX() / 72];

		if (TILETYPE::GROUND != TargetTileType)
		{
			TargetLocation_Player = StartLocation_Player;
			return;
		}
		Partner->SetStartLocation(Partner->GetActorLocation());
		CurTurnType = TurnType::PlayerMove;
	}

	FVector2D StartLocation_Partner = Partner->SetStartLocation(Partner->GetActorLocation());

	FVector2D TargetLocation_Partner = Partner->SetTargetLocation(Player->GetStartLocation());

	FVector2D DIR_Partner = TargetLocation_Partner - StartLocation_Partner;
	if (DIR_Partner / 72 == FVector2D::DOWN) 
	{
		Partner->SetDir(DIR::Down);
	}
	else if (DIR_Partner / 72 == FVector2D::DOWN + FVector2D::RIGHT)
	{
		Partner->SetDir(DIR::Right_Down);
	}
	else if (DIR_Partner / 72 == FVector2D::RIGHT)
	{
		Partner->SetDir(DIR::Right);
	}
	else if (DIR_Partner / 72 == FVector2D::RIGHT + FVector2D::UP)
	{
		Partner->SetDir(DIR::Right_Up);
	}
	else if (DIR_Partner / 72 == FVector2D::UP)
	{
		Partner->SetDir(DIR::Up);
	}
	else if (DIR_Partner / 72 == FVector2D::UP + FVector2D::LEFT)
	{
		Partner->SetDir(DIR::Left_Up);
	}
	else if (DIR_Partner / 72 == FVector2D::LEFT)
	{
		Partner->SetDir(DIR::Left);
	}
	else if (DIR_Partner / 72 == FVector2D::DOWN + FVector2D::LEFT)
	{
		Partner->SetDir(DIR::Left_Down);
	}


	

}