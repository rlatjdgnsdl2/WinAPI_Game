#include "DungeonManager.h"
#include "DungeonRoom.h"

DungeonManager::DungeonManager()
{
}

void DungeonManager::PlusRoomVector()
{
	roomVector.push_back(new DungeonRoom());
}
