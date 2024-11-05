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
	LEFT_DOWN = 1,
	DOWN,
	RIGHT_DOWN,
	LEFT,
	RIGHT=6,
	LEFT_UP,
	UP,
	RIGHT_UP
};

