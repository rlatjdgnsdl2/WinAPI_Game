#pragma once



//	��������
enum class ERenderOrder
{
	BACKGROUND = -1000,
	COLMAP = -999,
	PLAYER = 0,
	UI = 10000,
};
//---------------------------------------------------
//	Ÿ�ϸ�
enum class TileType {
	GROUND = 0,
	WALL,
	WATER
};
//---------------------------------------------------
//	����
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
//---------------------------------------------------
//	��������
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

enum class Pokemon_Type 
{
	Fire,
	Water
};

enum class SkillType
{
	NormalAttack,
	SpecialAttack,
	UseItem
};


enum class ECollisionGroup
{
	PlayerBody,
	MonsterBody,
	PlayerAttack,
	MonsterAttack
};
//---------------------------------------------------

