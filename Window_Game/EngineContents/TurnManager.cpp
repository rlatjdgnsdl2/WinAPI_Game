#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineCore/EngineAPICore.h>
#include "Player.h"


ATurnManager::ATurnManager()
{

}

ATurnManager::~ATurnManager() 
{

}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();
	AActor* PlayerActor = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(PlayerActor);
}

void ATurnManager::Tick(float _DeltaTime)
{

	switch (CurTurnType)
	{
	case TurnType::PlayerIdle:
		PlayerIdle();
		break;
	case TurnType::PlayerMove:
		PlayerMove(_DeltaTime);
		break;
	}
}



