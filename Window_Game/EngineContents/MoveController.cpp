#include "PreCompile.h"
#include "MoveController.h"



UMoveController::UMoveController() 
{

}
UMoveController::~UMoveController() 
{

}

void UMoveController::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration / 0.5f);
	GetActor()->SetActorLocation(NewLocation);
}
