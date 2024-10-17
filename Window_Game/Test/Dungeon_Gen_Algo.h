#pragma once
#include <vector>
#include "Room.h"
class Dungeon_Gen_Algo
{
public:
	std::vector<std::vector<int>>& dungeon;
	std::vector<Room>& rooms;
	Dungeon_Gen_Algo(std::vector<std::vector<int>>& _dungeon, std::vector<Room>& _rooms);
	virtual ~Dungeon_Gen_Algo();
	virtual void GenerateDungeon() = 0;
	
protected:
	virtual void SliceDungeon() = 0;
	virtual void GenerateRoom() = 0;
	virtual void PlaceRoom() = 0;
private:
	
};

