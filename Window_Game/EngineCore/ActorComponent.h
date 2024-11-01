#pragma once
#include <EngineBase/Object.h>

// 설명 :
class UActorComponent : public UObject
{
public:
	
	friend class AActor;

	typedef UActorComponent Super;

	// constrcuter destructer
	UActorComponent();

	// 객체화 못시키게 하는법
	virtual ~UActorComponent() =0;

	// delete Function
	UActorComponent(const UActorComponent& _Other) = delete;
	UActorComponent(UActorComponent&& _Other) noexcept = delete;
	UActorComponent& operator=(const UActorComponent& _Other) = delete;
	UActorComponent& operator=(UActorComponent&& _Other) noexcept = delete;

	virtual void BeginPlay() {}
	virtual void ComponentTick(float _DeltaTime) {}

	class AActor* GetActor()
	{
		return ParentActor;
	}

protected:

private:
	class AActor* ParentActor;
};

