#pragma once



struct Room {
	int x, y, width, height;
	bool isValid() const {
		return width > 0 && height > 0;
	}
};

struct Node {
	int x, y, width, height;
	Room room;
	Node* left = nullptr;
	Node* right = nullptr;
	bool isLeaf() const { return left == nullptr && right == nullptr; }

	~Node() {
		delete left;
		delete right;
	}
};


struct AnimInfo
{
	AnimInfo() {}
	AnimInfo(
		int _AttackAnimCount,
		int _HurtAnimCount,
		int _IdleAnimCount,
		int _WalkAnimCount) :
		AttackAnimCount(_AttackAnimCount),
		HurtAnimCount(_HurtAnimCount),
		IdleAnimCount(_IdleAnimCount),
		WalkAnimCount(_WalkAnimCount) {}
	int AttackAnimCount{};
	int HurtAnimCount{};
	int IdleAnimCount{};
	int WalkAnimCount{};
};

struct PokemonInfo
{
	PokemonInfo() {}
	PokemonInfo(
		PokemonType _PokemonType,
		int _Level,
		int _MaxHp,
		int _Attack,
		int _Speed) :
		PokemonType(_PokemonType),
		Level(_Level),
		MaxHp(_MaxHp),
		ATK(_Attack),
		SPD(_Speed) {
	}
	PokemonType PokemonType;
	int Level;
	int MaxHp;
	int CurHp;
	int ATK;
	int SPD;
	int MaxEXP;
	int EXP = 0;
};





struct DungeonInfo {
	std::vector<std::string> Pokemons_In_Dongeon;
};






