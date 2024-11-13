#pragma once



struct Room {
	int x, y, width, height;
	bool isValid() const {
		// 방이 유효하려면 너비와 높이가 0보다 커야 함
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


struct PokemonAnimaionInfo
{
	PokemonAnimaionInfo() {}
	PokemonAnimaionInfo(
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

struct PokemonAbility
{
	PokemonAbility() {}
	PokemonAbility(
		unsigned int _Level,
		unsigned int _Hp,
		unsigned int _Attack,
		unsigned int _Defense,
		unsigned int _Special_Attack,
		unsigned int _Special_Defense,
		unsigned int _Speed ) :
		Level(_Level),
		Hp(_Hp),
		Attack(_Attack),
		Defense(_Defense),
		Special_Attack(_Special_Attack),
		Special_Defense(_Special_Defense),
		Speed(_Speed) {}
	unsigned int Level{};
	unsigned int Hp{};
	unsigned int Attack{};
	unsigned int Defense{};
	unsigned int Special_Attack{};
	unsigned int Special_Defense{};
	unsigned int Speed{};
};


struct DungeonInfo {
	std::vector<std::string> Pokemons_In_Dongeon;
};






