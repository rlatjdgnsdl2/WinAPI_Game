#pragma once
#include "Room.h"
#include <vector>
class DungeonManager
{
private:
	std::vector<std::vector<int>> dungeon;
	std::vector<Room> rooms;
	std::vector<class Dungeon_Gen_Algo*> dungeon_Gen_Algos;
public:
	static const int WIDTH;
	static const int HEIGHT;
	static const int WALL;
	static const int PATH;

	~DungeonManager();
	DungeonManager();

	void InitDungeon();
	void GenerateDungeon(int _index);
	void PrintDungeon();
};

