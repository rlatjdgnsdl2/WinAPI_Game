#pragma once
#include "DungeonGenAlgorithm.h"

//	설명:
class UBasicAlgo : public UDungeonGenAlgorithm
{
public:
	//	constrcuter, destructer
	UBasicAlgo();
	~UBasicAlgo();

	//	delete Function
	UBasicAlgo(const UBasicAlgo& _Other) = delete;
	UBasicAlgo(UBasicAlgo&& _Other) noexcept = delete;
	UBasicAlgo& operator=(const UBasicAlgo& _Other) = delete;
	UBasicAlgo& operator=(UBasicAlgo&& _Other) noexcept = delete;

	

protected:
	

private:
	// UDungeonGenAlgorithm을(를) 통해 상속됨
	void SliceProcess(ADungeon& _Dungeon) override;
	void RoomGenProcess(ADungeon& _Dungeon) override;

};

