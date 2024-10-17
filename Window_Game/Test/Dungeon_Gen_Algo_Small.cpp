#include "Dungeon_Gen_Algo_Small.h"
#include "DungeonManager.h"

Dungeon_Gen_Algo_Small::Dungeon_Gen_Algo_Small(std::vector<std::vector<int>>& _dungeon, std::vector<Room>& _rooms):Dungeon_Gen_Algo(_dungeon,_rooms)
{
}

void Dungeon_Gen_Algo_Small::GenerateDungeon()
{
	SliceDungeon();
	GenerateRoom();
	PlaceRoom();
}

void Dungeon_Gen_Algo_Small::SliceDungeon()
{
	int value = rand() % 2;
	//if (value == 1) {
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				slicedDungeons.push_back(Room(
					((DungeonManager::WIDTH / 4) * j) + 3,
					((DungeonManager::HEIGHT / 4) * i) + 3,
					((DungeonManager::WIDTH - 8) / 4),
					((DungeonManager::HEIGHT - 8) / 2)));
			}
		}
	//}
}
void Dungeon_Gen_Algo_Small::GenerateRoom()
{
	rooms.push_back(Room(4, 4, 14, 20));
}


void Dungeon_Gen_Algo_Small::PlaceRoom()
{
	for (Room room : rooms) {
		for (int i = 0; i < room.height; i++)
		{
			for (int j = 0; j < room.width; j++)
			{
				if (i == 0 || j == 0 || i == room.height - 1 || j == room.width - 1)
					dungeon[room.startY + i][room.startX + j] = DungeonManager::WALL;
			}
		}
	}
}
