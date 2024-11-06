#include "PreCompile.h"
#include "BasicAlgo.h"



UBasicAlgo::UBasicAlgo() {};
UBasicAlgo::~UBasicAlgo() {};



void UBasicAlgo::SliceProcess(ADungeon& _Dungeon)
{
	FTransform UseableTrans = FTransform(FVector2D(_Dungeon.DungeonSize.X / 2, _Dungeon.DungeonSize.Y), _Dungeon.DungeonPos);


	FVector2D SlicedRoomSize = UseableTrans.Scale.Half();


	for (int _y = 0; _y < 2; _y++)
	{
		for (int _x = 0; _x < 2; _x++)
		{
			FVector2D Pos = FVector2D(UseableTrans.Location.iX() + SlicedRoomSize.iX() * _x, UseableTrans.Location.iY() + SlicedRoomSize.iY() * _y);
			FTransform SlicedRoomTrans = FTransform(SlicedRoomSize, Pos);
			_Dungeon.SlicedRooms.push_back(SlicedRoomTrans);
		}
	}




}

void UBasicAlgo::RoomGenProcess(ADungeon& _Dungeon)
{
	int GenableRoomCount = _Dungeon.SlicedRooms.size();

	int roomCount = 0;

	for (int i = 0; i < GenableRoomCount; i++)
	{
		
		
		// ·£´ý¹æ»ý¼º

	}

	int a = 0;

}


