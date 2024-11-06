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
		//	all tile Type
		std::vector<std::vector<TILETYPE>>TileTypes;
		//	room transform
		std::vector<FTransform> DungeonRooms;
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





protected:

private:
	DungeonData DungeonData;

};

