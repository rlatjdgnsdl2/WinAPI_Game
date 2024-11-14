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

enum class TurnType
{
	Player_Select,
	Open_Menu,
	Player_Select_Move,
	Player_Select_Skill,
	Player_Move,
	Player_Skill,
	Move_AI_Select,
	Skill_AI_Select,
	AI_Move,
	AI_Skill
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


