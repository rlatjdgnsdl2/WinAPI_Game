#pragma once
#include <EngineCore/EngineContentsCore.h>
//	����:
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

	const int ScaleRate = 3;

protected:
	void BeginPlay() override;
	void Tick() override;
private:



};

