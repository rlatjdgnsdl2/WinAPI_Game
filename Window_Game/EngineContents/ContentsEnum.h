#pragma once


enum class ERenderOrder
{
	BACKGROUND = -1000,
	COLMAP = -999,
	PLAYER = 0,
	ATTACK_Player = 100,
	UI = 10000,
};
enum class TileType
{
	None = -1,
	GROUND,
	WALL,
	WATER,
	FIRE
};
enum class PokemonType {
	WATER,
	FIRE,
	STONE
};


enum class CampType
{
	Player,
	Enemy
};

enum class SkillType
{
	NormalAttack,
	SpecialAttack,
	UseItem
};
enum class DIR
{
	Left_Down = 1,
	Down,
	Right_Down,
	Left,
	Right = 6,
	Left_Up,
	Up,
	Right_Up
};



enum class ECollisionGroup
{
	PlayerBody,
	MonsterBody,
};


