#include "DungeonRoom.h"
#include <stdlib.h>
#include <vector>


DungeonRoom::DungeonRoom() :roomSize{ 0,0 },MIN_SIZE{5}
{
	CreateRoom();
}

void DungeonRoom::CreateRoom()
{
	SetRoomSize();
	room.resize(roomSize.y,std::vector<int>(roomSize.x,0));
	SetBorderToWall();
}

void DungeonRoom::SetRoomSize()
{
	roomSize.x = (rand() % 8) + MIN_SIZE;
	roomSize.y = (rand() % 8) + MIN_SIZE;
}

void DungeonRoom::SetBorderToWall()
{
	for (int i = 0; i < roomSize.y; i++)
	{
		for (int j = 0; j < roomSize.x; j++)
		{
			if (i == 0 || j == 0 || i == roomSize.y - 1 || j == roomSize.x - 1) {
				room[i][j] = 1;
			}
		}
	}
}
