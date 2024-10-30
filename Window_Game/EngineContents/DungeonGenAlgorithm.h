#pragma once
#include <EngineBase/Object.h>

//	����: �������� �˰��� �������̽�
class UDungeonGenAlgorithm: public UObject
{
public:
	//	constrcuter, destructer
	UDungeonGenAlgorithm();
	virtual ~UDungeonGenAlgorithm();

	//	delete Function
	UDungeonGenAlgorithm(const UDungeonGenAlgorithm& _Other) = delete;
	UDungeonGenAlgorithm(UDungeonGenAlgorithm&& _Other) noexcept = delete;
	UDungeonGenAlgorithm& operator=(const UDungeonGenAlgorithm& _Other) = delete;
	UDungeonGenAlgorithm& operator=(UDungeonGenAlgorithm&& _Other) noexcept = delete;

	virtual void GenerateDungeon(class ADungeon& _Dungeon);
protected:
	void InitProcess(class ADungeon& _Dungeon);
	virtual void SliceProcess(class ADungeon& _Dungeon) =0;
	virtual void RoomGenProcess(class ADungeon& _Dungeon) =0;
	



private:

};

