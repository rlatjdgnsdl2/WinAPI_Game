#pragma once
#include "DungeonGenerator.h"

//	Ό³Έν:
class UTutorialGenerator : public UDungeonGenerator
{
public:
	//	constrcuter, destructer
	UTutorialGenerator();
	virtual ~UTutorialGenerator();

	//	delete Function
	UTutorialGenerator(const UTutorialGenerator& _Other) = delete;
	UTutorialGenerator(UTutorialGenerator&& _Other) noexcept = delete;
	UTutorialGenerator& operator=(const UTutorialGenerator& _Other) = delete;
	UTutorialGenerator& operator=(UTutorialGenerator&& _Other) noexcept = delete;

	void SetRandomHallWay() override;
	void SetRandomSizeRoom() override;

protected:

private:


	
};

