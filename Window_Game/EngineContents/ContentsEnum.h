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

enum class CampType
{
	Player,
	Enemy
};
enum class TurnType
{
	Player_Select,
	Player_Select_Move,
	Player_Select_Skill,
	Player_Move,
	Player_Skill,
	Move_AI_Select,
	Skill_AI_Select,
	AI_Move,
	AI_Skill,
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
	Right=6,
	Left_Up,
	Up,
	Right_Up
};

