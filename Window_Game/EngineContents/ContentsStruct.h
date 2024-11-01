#pragma once





struct Dungeon
{
	FTransform DungeonSize = FTransform(FVector2D{ 0,0 }, FVector2D{ 60,40 });
	std::vector<std::vector<int>> DungeonData;
	std::vector<FTransform> slicedRooms;
	std::vector<FTransform> InnerRooms;
};


