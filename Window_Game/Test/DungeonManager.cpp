#include "DungeonManager.h"
#include "Dungeon_Gen_Algo.h"
#include <iostream>

const int DungeonManager::HEIGHT = 48;
const int DungeonManager::WIDTH = 64;
const int DungeonManager::WALL = 1;
const int DungeonManager::PATH = 0;



DungeonManager::DungeonManager() :dungeon_Gen_Algos{ nullptr }
{
	InitDungeon();
}

DungeonManager::~DungeonManager()
{
	for (auto algo : dungeon_Gen_Algos) {
		delete algo;
	}
	dungeon_Gen_Algos.clear();
	for (auto room : rooms) {
		delete room;
	}
	rooms.clear();
}

void DungeonManager::InitDungeon()
{
	dungeon = std::vector<std::vector<int>>(HEIGHT, std::vector<int>(WIDTH, PATH));
	// 가장자리 4칸씩 벽으로 설정
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			if (x < 4 || x >= WIDTH - 4 || y < 4 || y >= HEIGHT - 4) {
				dungeon[y][x] = WALL;
			}
		}
	}
}

void DungeonManager::GenerateDungeon(int _index)
{
	if (dungeon_Gen_Algos[_index]!=nullptr) {
		dungeon_Gen_Algos[_index]->generate(dungeon,rooms);
	}
}

void DungeonManager::PrintDungeon() {
	for (const auto& row : dungeon) {
		for (int cell : row) {
			if (cell == WALL) {
				std::cout << "#";
			}
			else {
				std::cout << ".";
			}
		}
		std::cout << "\n";
	}
}
