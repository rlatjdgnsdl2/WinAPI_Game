#pragma once

//	Ό³Έν:
class ULevel
{
public:
	//	constrcuter, destructer
	ULevel() = default;
	~ULevel() = default;

	//	delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	void BeginPlay()
	{

	}
	void Tick()
	{
	}

protected:

private:

};

