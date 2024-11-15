#pragma once
#include "ActorComponent.h"

// ���� :
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


	// ���͸� ���������� Ʈ������ 
	FTransform GetActorTransform();

	// ���� ��ġ ������� ������ �Ұ��̴�.
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

