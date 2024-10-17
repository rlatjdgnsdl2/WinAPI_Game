#pragma once
#include <vector>
class Dungeon_Gen_Algo
{
public:
	virtual ~Dungeon_Gen_Algo();
	virtual void GenerateDungeon(std::vector<std::vector<int>>& dungeon) = 0;
	
protected:
	virtual void SliceDungeon() = 0;
private:
	
};

