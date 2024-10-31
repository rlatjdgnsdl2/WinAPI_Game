#include "PreCompile.h"
#include "Dungeon.h"

ADungeon::ADungeon():DungeonData(DungeonTrans.Scale.iY(), std::vector<int>(DungeonTrans.Scale.iX(), 1))
{

}
ADungeon::~ADungeon() 
{

}
void ADungeon::SetDungeonData(int _x, int _y, int _value)
{
	DungeonData[_y][_x] = _value;
}
