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
		char _AttackAnimCount,
		char _HurtAnimCount,
		char _IdleAnimCount,
		char _WalkAnimCount) :
		AttackAnimCount(_AttackAnimCount),
		HurtAnimCount(_HurtAnimCount),
		IdleAnimCount(_IdleAnimCount),
		WalkAnimCount(_WalkAnimCount) {}
	char AttackAnimCount{};
	char HurtAnimCount{};
	char IdleAnimCount{};
	char WalkAnimCount{};
};

struct PokemonAbility
{
	PokemonAbility() {}
	PokemonAbility(
		unsigned char _Level,
		unsigned char _Hp,
		unsigned char _Attack,
		unsigned char _Defense,
		unsigned char _Special_Attack,
		unsigned char _Special_Defense,
		unsigned char _Speed ) :
		Level(_Level),
		Hp(_Hp),
		Attack(_Attack),
		Defense(_Defense),
		Special_Attack(_Special_Attack),
		Special_Defense(_Special_Defense),
		Speed(_Speed) {}
	unsigned char Level{};
	unsigned char Hp{};
	unsigned char Attack{};
	unsigned char Defense{};
	unsigned char Special_Attack{};
	unsigned char Special_Defense{};
	unsigned char Speed{};
};


struct DungeonInfo {
	std::vector<std::string> Pokemons_In_Dongeon;
};






