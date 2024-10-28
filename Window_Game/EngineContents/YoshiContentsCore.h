#pragma once
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/EngineContentsCore.h>

//	Ό³Έν:
class YoshiContentsCore : public UEngineContentsCore
{
public:
	//	constrcuter, destructer
	YoshiContentsCore();
	~YoshiContentsCore();

	//	delete Function
	YoshiContentsCore(const YoshiContentsCore& _Other) = delete;
	YoshiContentsCore(YoshiContentsCore&& _Other) noexcept = delete;
	YoshiContentsCore& operator=(const YoshiContentsCore& _Other) = delete;
	YoshiContentsCore& operator=(YoshiContentsCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick() override;


private:
	ULevel* TitleLevel = nullptr;


};

