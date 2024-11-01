#include "PreCompile.h"
#include "DungeonGenAlgorithm.h"




UDungeonGenAlgorithm::UDungeonGenAlgorithm() {};
UDungeonGenAlgorithm::~UDungeonGenAlgorithm() {};

void UDungeonGenAlgorithm::GenerateDungeon(Dungeon& _Dungeon)
{
	InitProcess(_Dungeon);
	SliceProcess(_Dungeon);
	RoomGenProcess(_Dungeon);
    PrintDungeonData(_Dungeon);
    
}

void UDungeonGenAlgorithm::InitProcess(Dungeon& _Dungeon)
{
	_Dungeon.DungeonData.resize(60, std::vector<int>(40,1));
}



void UDungeonGenAlgorithm::PrintDungeonData(const Dungeon& _Dungeon) {
    std::vector<std::vector<int>> DungeonData = _Dungeon.DungeonData;
    for (const auto& row : DungeonData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

