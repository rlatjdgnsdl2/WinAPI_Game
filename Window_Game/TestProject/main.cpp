#include <EngineContents/DungeonGameMode.h>



int main()
{
	ADungeonGameMode DungeonMgr;
	DungeonMgr.GenerateDungeon("Basic");
	DungeonMgr.Print();
	return 0;
}