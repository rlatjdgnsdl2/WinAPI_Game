#include "PreCompile.h"
#include "Dungeon.h"

ADungeon::ADungeon():DungeonData(DungeonMaxSizeY, std::vector<int>(DungeonMaxSizeX, 0))
{

};
ADungeon::~ADungeon() 
{

}
void ADungeon::SetDungeonData(int _x, int _y, int _value)
{
	DungeonData[_y][_x] = _value;
}
;