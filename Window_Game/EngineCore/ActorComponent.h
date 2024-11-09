#pragma once
#include <EngineBase/Object.h>

// ���� :
class UActorComponent : public UObject
{
public:
	
	friend class AActor;

	typedef UActorComponent Super;

	// constrcuter destructer
	UActorComponent();
	virtual ~UActorComponent();

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
	bool IsActive() override
	{
		// �������� �ڽ��� ���� ���Ϳ��� ���ӵȴ�.
		// �θ�        true            true
		return UObject::IsActive() && GetActor()->IsActive();
	}


	bool IsDestroy() override
	{
		// �θ�        true            true
		return UObject::IsDestroy() || GetActor()->IsDestroy();
	}


protected:

private:
	class AActor* ParentActor;
};

