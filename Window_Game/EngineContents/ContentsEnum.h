#pragma once


enum class ERenderOrder
{
	BACKGROUND = -10,
	PLAYER = 0,
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

