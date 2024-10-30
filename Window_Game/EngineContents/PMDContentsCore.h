#pragma once
#include <EngineCore/EngineContentsCore.h>
//	Ό³Έν:
class PMDContentsCore :public UEngineContentsCore
{
public:
	//	constrcuter, destructer
	PMDContentsCore();
	~PMDContentsCore();
	//	delete Function
	PMDContentsCore(const PMDContentsCore& _Other) = delete;
	PMDContentsCore(PMDContentsCore&& _Other) noexcept = delete;
	PMDContentsCore& operator=(const PMDContentsCore& _Other) = delete;
	PMDContentsCore& operator=(PMDContentsCore&& _Other) noexcept = delete;

	static FVector2D GameViewSize;
	static int ScaleRate;

protected:
	void BeginPlay() override;
	void Tick() override;
private:



};

