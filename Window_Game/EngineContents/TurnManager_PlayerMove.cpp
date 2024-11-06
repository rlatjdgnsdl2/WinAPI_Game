#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "Partner.h"


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