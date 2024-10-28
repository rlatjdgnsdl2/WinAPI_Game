#pragma once

//	Ό³Έν:
class UEngineContentsCore
{
public:
	//	constrcuter, destructer
	UEngineContentsCore();
	~UEngineContentsCore();

	//	delete Function
	UEngineContentsCore(const UEngineContentsCore& _Other) = delete;
	UEngineContentsCore(UEngineContentsCore&& _Other) noexcept = delete;
	UEngineContentsCore& operator=(const UEngineContentsCore& _Other) = delete;
	UEngineContentsCore& operator=(UEngineContentsCore&& _Other) noexcept = delete;

	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;

protected:

private:

};

