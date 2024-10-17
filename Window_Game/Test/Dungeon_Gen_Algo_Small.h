#pragma once
#include "Dungeon_Gen_Algo.h"
class Dungeon_Gen_Algo_Small :public Dungeon_Gen_Algo
{
private:
	int sliceCount;
public:
	void GenerateDungeon(std::vector<std::vector<int>>& dungeon) override;
	void SliceDungeon(int _sliceCount) override;

};

