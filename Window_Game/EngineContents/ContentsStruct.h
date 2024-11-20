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
		WalkAnimCount(_WalkAnimCount) {
	}
	int AttackAnimCount{};
	int HurtAnimCount{};
	int IdleAnimCount{};
	int WalkAnimCount{};
};

struct PokemonInfo
{
	PokemonInfo() {}
	PokemonInfo(
		int _Level,
		int _MaxHp,
		int _Attack,
		int _Speed) :

		Level(_Level),
		MaxHp(_MaxHp),
		ATK(_Attack),
		SPD(_Speed) {
	}

	int Level;
	int MaxHp;
	int ATK;
	int SPD;
};

class DungeonTile
{
public:
	class USpriteRenderer* SpriteRenderer = nullptr;
	TileType TileType;
	FTransform TileTrans;
};


class UITile
{
public:
	class USpriteRenderer* SpriteRenderer = nullptr;

};






struct DungeonInfo {
	std::vector<std::string> Pokemons_In_Dongeon;
};






