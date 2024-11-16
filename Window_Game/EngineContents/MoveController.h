#pragma once
#include <EngineCore/ActorComponent.h>

//	설명:
class UMoveController :public UActorComponent
{
public:
	//	constrcuter, destructer
	UMoveController();
	virtual ~UMoveController();

	//	delete Function
	UMoveController(const UMoveController& _Other) = delete;
	UMoveController(UMoveController&& _Other) noexcept = delete;
	UMoveController& operator=(const UMoveController& _Other) = delete;
	UMoveController& operator=(UMoveController&& _Other) noexcept = delete;

	//	이동
	const FVector2D& GetTargetLocation() const {
		return TargetLocation;
	};
	const FIntPoint& GetTargetTile() {
		return ((TargetLocation.ConvertToPoint()) / 72);
	};
	const FIntPoint& GetTile() {
		return (GetActor()->GetActorLocation().ConvertToPoint()) / 72);
	};
	void SetTargetLocation(const FVector2D& _TargetLocation) {
		TargetLocation = _TargetLocation;
		StartLocation = GetActor()->GetActorLocation();
	};
	void SetTargetTile(const FIntPoint& _TargetTileIndex) {
		TargetLocation = _TargetTileIndex * 72.0f;
		StartLocation = GetActor()->GetActorLocation();
	};
	

	void ResetCurDuration() {
		CurDuration = 0.0f;
	}

	virtual void Move(float _DeltaTime);



protected:

private:
	float CurDuration;
	FVector2D StartLocation;
	FVector2D TargetLocation;

};

