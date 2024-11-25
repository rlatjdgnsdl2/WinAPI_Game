#pragma once


enum class ERenderOrder
{
	BackGround = -1000,
	ColMap = -999,
	Item = -10,
	Player = 0,
	
	AttacK_Player = 100,
	UI_BackGround = 5000,
	UI_Basic = 10000,
	UI_Image = 20000,
	UI_Text = 30000,
	FADE = 40000
};
enum class TileType
{
	None = -1,
	GROUND,
	WALL,
	WATER
};


enum class CampType
{
	None = -1,
	Player,
	Enemy
};

enum class SkillType
{
	None = -1,
	NormalAttack,
	SpecialAttack,
	UseItem
};
enum class DIR
{
	None = -1,
	Left_Down = 1,
	Down,
	Right_Down,
	Left,
	Right = 6,
	Left_Up,
	Up,
	Right_Up,
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
	Male, Female,
	Comma,
	MAX=79
};


enum class TurnType
{
	Player_Select,
	Open_UI,
	Player_Select_Move,
	Player_Select_Skill,
	Player_Move,
	Player_Skill_Start,
	Player_Skill,
	Player_Skill_End,
	Move_AI_Select,
	Skill_AI_Select,
	AI_Move,
	AI_Skill_Start,
	AI_Skill,
	AI_Skill_End
};


enum class MenuType {
	None,
	OpenMenu,
	ShowMenu,
	CloseMenu,
	OpenSkill,
	ShowSkill,
	CloseSkill,
	OpenItem,
	SHowItem,
	CloseItem
};
enum class Color {
	Red,
	Pink,
	White,
	Blue,
	Green,
	Yellow,
};



