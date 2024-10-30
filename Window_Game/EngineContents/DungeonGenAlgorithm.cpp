#include "PreCompile.h"
#include "DungeonGenAlgorithm.h"
#include "Dungeon.h"



UDungeonGenAlgorithm::UDungeonGenAlgorithm() {};
UDungeonGenAlgorithm::~UDungeonGenAlgorithm() {};

void UDungeonGenAlgorithm::GenerateDungeon(ADungeon& _Dungeon)
{
	InitProcess(_Dungeon);
	SliceProcess(_Dungeon);
	RoomGenProcess(_Dungeon);
}

void UDungeonGenAlgorithm::InitProcess(ADungeon& _Dungeon)
{
	
	for (int y = 0; y < DungeonMaxSizeY; y++)
	{
		for (int x = 0; x < DungeonMaxSizeX; x++)
		{
			if (y < 3 || x<3 || y>DungeonMaxSizeY - 1 - 3 || x > DungeonMaxSizeX - 4) {
				_Dungeon.SetDungeonData(y, x, 0);
			}
		}
	}
	ADungeon& TestDun = _Dungeon;
}

