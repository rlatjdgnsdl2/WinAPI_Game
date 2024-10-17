#pragma once
#include "Dungeon_Gen_Algo.h"
#include <vector>
#include "Room.h"

class Dungeon_Gen_Algo_Small :public Dungeon_Gen_Algo
{
private:
	std::vector<Room> slicedDungeons;
	void SliceDungeon() override;
	void PlaceRoom() override;
	void GenerateDungeon() override;
	void GenerateRoom() override;

	
public:
	Dungeon_Gen_Algo_Small(std::vector<std::vector<int>>& _dungeon, std::vector<Room>& _rooms);

};

