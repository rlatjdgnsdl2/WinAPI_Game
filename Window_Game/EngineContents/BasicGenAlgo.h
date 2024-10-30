#pragma once
#include "DungeonGenAlgorithm.h"

//	Ό³Έν:
class UDGBasicGenAlgo : public UDungeonGenAlgorithm
{
public:
	//	constrcuter, destructer
	UDGBasicGenAlgo();
	~UDGBasicGenAlgo();

	//	delete Function
	UDGBasicGenAlgo(const UDGBasicGenAlgo& _Other) = delete;
	UDGBasicGenAlgo(UDGBasicGenAlgo&& _Other) noexcept = delete;
	UDGBasicGenAlgo& operator=(const UDGBasicGenAlgo& _Other) = delete;
	UDGBasicGenAlgo& operator=(UDGBasicGenAlgo&& _Other) noexcept = delete;


	virtual void GenerateDungeon(class ADungeon& _Dungeon) override;
protected:
	virtual void SliceProcess() override;
	virtual void RoomGenProcess() override;

private:

};

