#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"


void ATurnManager::PlayerMove(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	Player->GetSpriteRenderer()->ChangeAnimation("WalkAnim_" + std::to_string((int)Player->GetDir()));
	Player->GetSpriteRenderer()->SetSpriteScale();
	FVector2D NewLocation = FVector2D::LerpClimp(Player->GetStartLocation(), Player->GetTargetLocation(), CurDuration * 2.0f);
	Player->SetActorLocation(NewLocation);

	if (CurDuration > 1.0f / 2.0f)
	{
		CurTurnType = TurnType::PlayerIdle;
	}
}