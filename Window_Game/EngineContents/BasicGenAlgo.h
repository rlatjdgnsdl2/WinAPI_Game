#pragma once
#include "DungeonGenAlgorithm.h"

//	����:
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
	

private:
	// UDungeonGenAlgorithm��(��) ���� ��ӵ�
	void SliceProcess(ADungeon& _Dungeon) override;
	void RoomGenProcess(ADungeon& _Dungeon) override;

};

