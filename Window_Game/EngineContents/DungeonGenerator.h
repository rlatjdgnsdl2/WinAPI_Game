#pragma once
#include <EngineBase/Object.h>

//	Ό³Έν:
class UDungeonGenerator :public UObject
{
public:
	//	constrcuter, destructer
	UDungeonGenerator();
	virtual ~UDungeonGenerator();

	//	delete Function
	UDungeonGenerator(const UDungeonGenerator& _Other) = delete;
	UDungeonGenerator(UDungeonGenerator&& _Other) noexcept = delete;
	UDungeonGenerator& operator=(const UDungeonGenerator& _Other) = delete;
	UDungeonGenerator& operator=(UDungeonGenerator&& _Other) noexcept = delete;

	virtual void GenerateDungeon(class ATileMap* _Dungeon);
	
	virtual void SetAllWall();
	virtual void SetRandomSizeRoom()=0;
	virtual void SetRandomHallWay()=0;
	


protected:
	class ATileMap* Dungeon = nullptr;

private:
	

};

