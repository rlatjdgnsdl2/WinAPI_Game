#pragma once
#include "ActorComponent.h"

// 설명 :
class USceneComponent : public UActorComponent
{
public:
	// constrcuter destructer
	USceneComponent();
	virtual ~USceneComponent();

	// delete Function
	USceneComponent(const USceneComponent& _Other) = delete;
	USceneComponent(USceneComponent&& _Other) noexcept = delete;
	USceneComponent& operator=(const USceneComponent& _Other) = delete;
	USceneComponent& operator=(USceneComponent&& _Other) noexcept = delete;

	FTransform GetTransform() const
	{
		return Transform;
	}
	FVector2D GetComponentScale() const
	{
		return Transform.Scale;
	}
	FVector2D GetComponentLocation() const 
	{
		return Transform.Location;
	}


	// 엑터를 기준으로한 트랜스폼 
	FTransform GetActorTransform();

	// 액터 위치 기반으로 랜더링 할것이다.
	void SetComponentLocation(const FVector2D& _Location)
	{
		Transform.Location = _Location;
	}

	void SetComponentScale(const FVector2D& _Scale)
	{
		Transform.Scale = _Scale;
	}

protected:

private:
	FTransform Transform;
};

