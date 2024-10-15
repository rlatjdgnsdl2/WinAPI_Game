#pragma once
#include "StructList.h"
#include <vector>

class DungeonRoom
{
private:
	Point roomSize;
	const int MIN_SIZE;
	std::vector<std::vector<int>> room;
	void SetRoomSize();
	void SetBorderToWall();
public:
	DungeonRoom();
	
	void CreateRoom();
	
};

