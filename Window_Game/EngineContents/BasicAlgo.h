#pragma once
#include "DungeonGenAlgorithm.h"

//	����:
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
	// UDungeonGenAlgorithm��(��) ���� ��ӵ�
	void SliceProcess(Dungeon& _Dungeon) override;
	void RoomGenProcess(Dungeon& _Dungeon) override;

};
