#pragma once


//	설명:
class AActor
{
public:
	//	Level은 Actor에 접근가능
	friend class ULevel;

	//	constrcuter, destructer
	AActor();
	virtual ~AActor();

	//	delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

	//	virtual 
	virtual void BeginPlay() {}
	virtual void Tick(float _DeltaTime) {}

	//	일반
	class ULevel* GetWorld() { return World; }
	void SetActorLocation(FVector2D _Location)
	{
		Transform.Location = _Location;
	}

	void AddActorLocation(FVector2D _Direction)
	{
		Transform.Location += _Direction;
	}

	void SetActorScale(FVector2D _Scale)
	{
		Transform.Scale = _Scale;
	}

	FVector2D GetActorLocation()
	{
		return Transform.Location;
	}

protected:

private:
	//	일반
	class ULevel* World = nullptr;
	FTransform Transform;
};

