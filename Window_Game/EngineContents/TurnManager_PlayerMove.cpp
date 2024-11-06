#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "Dungeon.h"
#include "Partner.h"





void ATurnManager::InitPlayerMove(DIR direction, FVector2D moveVector)
{
	Player->SetDir(direction);
	FVector2D StartLocation = Player->SetStartLocation(Player->GetActorLocation());
	FVector2D TargetLocation = Player->SetTargetLocation(StartLocation + moveVector);
	TILETYPE TargetTileType = Dungeon->GetDungeonData()->TileTypes[TargetLocation.iY() / 72][TargetLocation.iX() / 72];

	if (TILETYPE::GROUND != TargetTileType) {
		Player->SetTargetLocation(StartLocation); // 이동 불가시 원래 위치로
		return;
	}

	Partner->SetStartLocation(Partner->GetActorLocation());
	CurTurnType = TurnType::PlayerMove;
}

void ATurnManager::SetPartnerDir()
{
	FVector2D StartLocation_Partner = Partner->SetStartLocation(Partner->GetActorLocation());
	FVector2D TargetLocation_Partner = Partner->SetTargetLocation(Player->GetStartLocation());
	FVector2D DIR_Partner = TargetLocation_Partner - StartLocation_Partner;

	if (DIR_Partner / 72 == FVector2D::DOWN) Partner->SetDir(DIR::Down);
	else if (DIR_Partner / 72 == FVector2D::DOWN + FVector2D::RIGHT) Partner->SetDir(DIR::Right_Down);
	else if (DIR_Partner / 72 == FVector2D::RIGHT) Partner->SetDir(DIR::Right);
	else if (DIR_Partner / 72 == FVector2D::RIGHT + FVector2D::UP) Partner->SetDir(DIR::Right_Up);
	else if (DIR_Partner / 72 == FVector2D::UP) Partner->SetDir(DIR::Up);
	else if (DIR_Partner / 72 == FVector2D::UP + FVector2D::LEFT) Partner->SetDir(DIR::Left_Up);
	else if (DIR_Partner / 72 == FVector2D::LEFT) Partner->SetDir(DIR::Left);
	else if (DIR_Partner / 72 == FVector2D::DOWN + FVector2D::LEFT) Partner->SetDir(DIR::Left_Down);
}



void ATurnManager::PlayerMove(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D PlayerNewLocation = FVector2D::LerpClimp(Player->GetStartLocation(), Player->GetTargetLocation(), CurDuration * 2.0f);
	Player->SetActorLocation(PlayerNewLocation);
	FVector2D PartnerNewLocation = FVector2D::LerpClimp(Partner->GetStartLocation(), Partner->GetTargetLocation(), CurDuration * 2.0f);
	Partner->SetActorLocation(PartnerNewLocation);
	Player->Move();
	Partner->Move();

	if (CurDuration > 1.0f / 2.0f)
	{
		CurTurnType = TurnType::PlayerIdle;
	}
}