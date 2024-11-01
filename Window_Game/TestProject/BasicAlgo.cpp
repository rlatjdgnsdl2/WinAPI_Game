#include "PreCompile.h"
#include "BasicAlgo.h"



UBasicAlgo::UBasicAlgo() {};
UBasicAlgo::~UBasicAlgo() {};



void UBasicAlgo::SliceProcess(Dungeon& _Dungeon)
{
	FTransform UseableTrans = FTransform(FVector2D(_Dungeon.DungeonSize.X / 2, _Dungeon.DungeonSize.Y), _Dungeon.DungeonPos);


	FVector2D SlicedRoomSize = UseableTrans.Scale.Half();
	int a = 0;

	for (int _y = 0; _y < 2; _y++)
	{
		for (int _x = 0; _x < 2; _x++)
		{
			FVector2D Pos = FVector2D(UseableTrans.Location.iX() + SlicedRoomSize.iX() * _x, UseableTrans.Location.iY() + SlicedRoomSize.iY() * _y);
			FTransform SlicedRoomTrans = FTransform(SlicedRoomSize, Pos);
			_Dungeon.SlicedRooms.push_back(SlicedRoomTrans);

		}
	}



	int a1 = 0;
}

void UBasicAlgo::RoomGenProcess(Dungeon& _Dungeon)
{

}


