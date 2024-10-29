#pragma once


//	����:
class AActor
{
public:
	//	Level�� Actor�� ���ٰ���
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

	//	�Ϲ�
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
	//	�Ϲ�
	class ULevel* World = nullptr;
	FTransform Transform;
};

