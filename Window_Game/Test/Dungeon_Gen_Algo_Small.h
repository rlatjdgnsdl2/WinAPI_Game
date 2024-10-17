#pragma once
#include "Dungeon_Gen_Algo.h"
class Dungeon_Gen_Algo_Small :public Dungeon_Gen_Algo
{
private:
	void SliceDungeon() override;
	
public:
	void GenerateDungeon(std::vector<std::vector<int>>& dungeon) override;

};

