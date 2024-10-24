#pragma once

//	Ό³Έν:
class AActor
{
public:
	//	constrcuter, destructer
	AActor() = default;
	~AActor() = default;

	//	delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

protected:

private:

};

