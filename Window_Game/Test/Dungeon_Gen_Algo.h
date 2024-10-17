#pragma once
#include <vector>
class Dungeon_Gen_Algo
{
public:
	virtual void GenerateDungeon(std::vector<std::vector<int>>& dungeon) = 0;
	
protected:
	virtual void SliceDungeon(int _sliceCount) = 0;
private:
	virtual ~Dungeon_Gen_Algo();
	
};

