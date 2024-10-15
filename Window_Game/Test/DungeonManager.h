#pragma once
#include "StructList.h"
#include <vector>
#include <unordered_map>
#include "EnumList.h"
class DungeonManager
{
private:
	std::vector<std::vector<int>> dungeon;
	std::unordered_map<DUNGEON_BUILD_ALGO, class DungeonBuildAlgo*> buildAlgoVector;
	std::vector<class DungeonRoom*> roomVector;
public:
	DungeonManager();
	void PlusRoomVector();




};

