#pragma once
#include <vector>
class Dungeon_Gen_Algo
{
public:
	virtual void generate(std::vector<std::vector<int>>& dungeon, std::vector<class Room*>& rooms) = 0;
};

