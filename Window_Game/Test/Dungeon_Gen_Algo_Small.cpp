#include "Dungeon_Gen_Algo_Small.h"
#include "DungeonManager.h"
#include <random>

Dungeon_Gen_Algo_Small::Dungeon_Gen_Algo_Small(std::vector<std::vector<int>>& _dungeon, std::vector<Room>& _rooms) :Dungeon_Gen_Algo(_dungeon, _rooms)
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
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			slicedDungeons.push_back(Room(
				((DungeonManager::WIDTH - 8) / 4) * j + 4,
				((DungeonManager::HEIGHT - 8) / 2) * i + 4,
				(DungeonManager::WIDTH - 8) / 4,
				(DungeonManager::HEIGHT - 8) / 2));
		}
	}
	
}
void Dungeon_Gen_Algo_Small::GenerateRoom()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	for (int i = 0; i < 4; i++)
	{
		while (true) {
			std::uniform_int_distribution<> randWidth(5, slicedDungeons[i].width);  // 너비: 최소 1에서 최대 방 너비
			std::uniform_int_distribution<> randHeight(5, slicedDungeons[i].height);// 높이: 최소 1에서 최대 방 높이
			int randomRoomWidth = randWidth(gen);
			int randomRoomHeight = randHeight(gen);
			std::uniform_int_distribution<> randStartX(slicedDungeons[i].startX, slicedDungeons[i].startX + slicedDungeons[i].width- randomRoomWidth);  // x 좌표: 0부터 최대 x 범위
			std::uniform_int_distribution<> randStartY(slicedDungeons[i].startY, slicedDungeons[i].startY + slicedDungeons[i].height - randomRoomHeight); // y 좌표: 0부터 최대 y 범위
			int randomRoomX = randStartX(gen);
			int randomRoomY = randStartY(gen);
			
			if (randomRoomX + randomRoomWidth <= slicedDungeons[i].startX+slicedDungeons[i].width && randomRoomY + randomRoomHeight <= slicedDungeons[i].startY+slicedDungeons[i].height) {
				rooms.push_back(Room(randomRoomX, randomRoomY, randomRoomWidth, randomRoomHeight));
				break;  // 경계를 넘지 않으면 방 생성 완료
			}
		}
	}




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
