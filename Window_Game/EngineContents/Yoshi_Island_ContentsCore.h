#pragma once
#include <EngineCore/EngineContentsCore.h>

//	Ό³Έν:
class Yoshi_Island_ContentsCore : public UEngineContentsCore
{
public:
	//	constrcuter, destructer
	Yoshi_Island_ContentsCore();
	~Yoshi_Island_ContentsCore();

	//	delete Function
	Yoshi_Island_ContentsCore(const Yoshi_Island_ContentsCore& _Other) = delete;
	Yoshi_Island_ContentsCore(Yoshi_Island_ContentsCore&& _Other) noexcept = delete;
	Yoshi_Island_ContentsCore& operator=(const Yoshi_Island_ContentsCore& _Other) = delete;
	Yoshi_Island_ContentsCore& operator=(Yoshi_Island_ContentsCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick() override;


private:
	ULevel* TitleLevel;


};

