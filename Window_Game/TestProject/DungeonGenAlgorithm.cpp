#include "PreCompile.h"
#include "DungeonGenAlgorithm.h"




UDungeonGenAlgorithm::UDungeonGenAlgorithm() {};
UDungeonGenAlgorithm::~UDungeonGenAlgorithm() {};

void UDungeonGenAlgorithm::GenerateDungeon(ADungeon& _Dungeon)
{
	InitProcess(_Dungeon);
	SliceProcess(_Dungeon);
	RoomGenProcess(_Dungeon);
    PrintDungeonData(_Dungeon);
    
}





void UDungeonGenAlgorithm::InitProcess(ADungeon& _Dungeon)
{
	_Dungeon.DungeonData.resize(40, std::vector<int>(60, 1));
}



void UDungeonGenAlgorithm::PrintDungeonData(const ADungeon& _Dungeon) {
	std::vector<std::vector<int>> DungeonData = _Dungeon.DungeonData;

	for (int y = 0; y < _Dungeon.DungeonSize.iY(); y++)
	{
		for (int x = 0; x < _Dungeon.DungeonSize.iX(); x++)
		{
			switch (_Dungeon.DungeonData[y][x]) {
			case 0:
				std::cout << "бр";
				break;
			case 1:
				std::cout << "бс";
				break;
			}
			
		}
		std::cout << std::endl;
	}

}


