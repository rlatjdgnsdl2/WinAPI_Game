#pragma once


enum class ERenderOrder
{
	BACKGROUND = -1000,
	COLMAP = -999,
	PLAYER = 0,
	UI = 10000,
};


enum class TILETYPE {
	GROUND = 0,
	WALL,
	WATER
};


enum class STATE 
{
	IDLE,
	WAIK,
	ATTACK,
	DAMAGE
};
enum class DIR
{
	Left_Down = 1,
	Down,
	Right_Down,
	Left,
	Right=6,
	Left_Up,
	Up,
	Right_Up
};

