#pragma once


enum class ERenderOrder
{
	BACKGROUND = -1000,
	COLMAP = -999,
	PLAYER = 0,
	ATTACK_Player = 100,
	UI_BACKGROUND = 5000,
	UI_BASIC = 10000,
	UI_IMAGE = 20000,
	UI_Text = 30000
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
	MonsterBody
};


enum class Text_Index
{
	a = 0, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
	A , B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Zero,
	Dot, Plus, Minus,
	Exclamation = 67,
	Question = 69,
	SmallQuotation_F, SmallQuotation_B,
	BigQuotation_F, BigQuotation_B,
	Male, Female,
	SpaceBar = 77,
	MAX
};


enum class TurnType
{
	Player_Select,
	Open_UI,
	Player_Select_Move,
	Player_Select_Skill,
	Player_Move,
	Player_Skill,
	Move_AI_Select,
	Skill_AI_Select,
	AI_Move,
	AI_Skill

};


enum class MenuType {
	Menu,
	Skill,
	Item,
	Team,
	Close,
	NextFloor
};


