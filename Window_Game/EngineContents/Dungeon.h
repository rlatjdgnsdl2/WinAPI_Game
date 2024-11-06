#pragma once
#include "TileMap.h"

//	Ό³Έν:
class ADungeon : public ATileMap
{
public:
	class DungeonData
	{
	public:
		std::string CurDungeonName;
		std::vector<std::vector<TILETYPE>>TileTypes;
		std::vector<FTransform> DungeonRooms;
		const int BoderSize = 5;
		FIntPoint DungeonSize = { 60,40 };
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

	void SetDungeonName(std::string_view _DungeonName) {
		DungeonData.CurDungeonName = _DungeonName;
	}
	void SetAllWall();
	void SliceDungeon();

	void SetRoom();
	void SetHallWay();

	void SetBorderWall();
	void SetNaturally();

protected:

private:
	DungeonData DungeonData;

};

