#pragma once
#include "TileMap.h"

//	Ό³Έν:
class ADungeon : public ATileMap
{
public:
	class DungeonData
	{
	public:
		std::string CurDungeonName = "BeachCave";
		std::vector<std::vector<TileType>>TileTypes;
		std::vector<FTransform> SlicedDungeons;
		std::vector<FTransform> DungeonRooms;
		std::vector<Room>Rooms;
		const int BoderSize = 5;
		FIntPoint DungeonSize = { 60,40 };
		FIntPoint GenableDungeonSize = { 50,30 };
		FVector2D TileSize = { 72,72 };
	};

	//	constrcuter, destructer
	ADungeon();
	virtual ~ADungeon();
	//	delete Function
	ADungeon(const ADungeon& _Other) = delete;
	ADungeon(ADungeon&& _Other) noexcept = delete;
	ADungeon& operator=(const ADungeon& _Other) = delete;
	ADungeon& operator=(ADungeon&& _Other) noexcept = delete;

	const int MIN_SIZE = 10;
	const int MAX_SIZE = 20;



	void SetDungeonName(std::string_view _DungeonName) {
		DungeonData.CurDungeonName = _DungeonName;
	}

	DungeonData* GetDungeonData()
	{
		return &DungeonData;
	};
	


	void SetAllWall();
	void SliceDungeon();

	void SetRoom();
	void SetHallWay();

	void SetBorderWall();
	void SetNaturally();

	bool IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms);

protected:

private:
	DungeonData DungeonData;

};

