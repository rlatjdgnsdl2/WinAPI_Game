#pragma once

//	����:
class AActor
{
public:
	friend class ULevel;
	//	constrcuter, destructer
	AActor() = default;
	~AActor() = default;

	//	delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

	virtual void BeginPlay() {}
	virtual void Tick() {}
	virtual void Render() {}

	ULevel* GetWorld()
	{
		return World;
	}

protected:

private:
	ULevel* World = nullptr;
};

