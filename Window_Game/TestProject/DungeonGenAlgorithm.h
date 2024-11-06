#pragma once
#include <EngineBase/Object.h>

//	설명: 던전생성 알고리즘 인터페이스
class UDungeonGenAlgorithm: public UObject
{
public:
	typedef UDungeonGenAlgorithm Super;
	//	constrcuter, destructer
	UDungeonGenAlgorithm();
	virtual ~UDungeonGenAlgorithm();

	//	delete Function
	UDungeonGenAlgorithm(const UDungeonGenAlgorithm& _Other) = delete;
	UDungeonGenAlgorithm(UDungeonGenAlgorithm&& _Other) noexcept = delete;
	UDungeonGenAlgorithm& operator=(const UDungeonGenAlgorithm& _Other) = delete;
	UDungeonGenAlgorithm& operator=(UDungeonGenAlgorithm&& _Other) noexcept = delete;

	virtual void GenerateDungeon(ADungeon& _Dungeon);
protected:
	void InitProcess(ADungeon& _Dungeon);
	virtual void SliceProcess(ADungeon& _Dungeon) =0;
	virtual void RoomGenProcess(ADungeon& _Dungeon) =0;

	void PrintDungeonData(const ADungeon& _Dungeon);
	



private:

};

