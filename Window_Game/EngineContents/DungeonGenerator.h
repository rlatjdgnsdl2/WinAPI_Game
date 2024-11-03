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
	
	virtual void AllSetWall();
	virtual void SetRandomSizeRoom();
	virtual void SetRandomHallWay();
	


protected:

private:
	class ATileMap* Dungeon = nullptr;

};

