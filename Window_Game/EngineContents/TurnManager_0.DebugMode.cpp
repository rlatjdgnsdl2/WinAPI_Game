#include "PreCompile.h"
#include "TurnManager.h"
#include <EnginePlatform/EngineInput.h>

void ATurnManager::DebugMode(float _DeltaTime) 
{
	int a = 0;
	if (true == UEngineInput::GetInst().IsPress('I'))
	{
		FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::UP * 72;
		GetWorld()->SetCameraPos(NewCameraPos);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress('J'))
	{
		FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::LEFT * 72;
		GetWorld()->SetCameraPos(NewCameraPos);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress('K'))
	{
		FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::DOWN * 72;
		GetWorld()->SetCameraPos(NewCameraPos);
		return;
	}
	if (true == UEngineInput::GetInst().IsPress('L'))
	{
		FVector2D NewCameraPos = GetWorld()->GetCameraPos() + FVector2D::RIGHT * 72;
		GetWorld()->SetCameraPos(NewCameraPos);
		return;
	}
}
