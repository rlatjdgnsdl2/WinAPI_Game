#pragma once



struct Room {
	int x{};
	int y{};
	int width{};
	int height{};
	bool isValid() const {
		return width > 0 && height > 0;
	}
};

struct RoomNode {
	int x{};
	int y{};
	int width{};
	int height{};
	Room room{};
	RoomNode* left = nullptr;
	RoomNode* right = nullptr;
	bool isLeaf() const { return left == nullptr && right == nullptr; }

	~RoomNode() {
		delete left;
		delete right;
	}
};

;


struct AnimInfo
{
	AnimInfo(
		int _AttackAnimCount,
		int _HurtAnimCount,
		int _IdleAnimCount,
		int _ShootAnimCount,
		int _WalkAnimCount) :
		AttackAnimCount(_AttackAnimCount),
		HurtAnimCount(_HurtAnimCount),
		IdleAnimCount(_IdleAnimCount),
		ShootAnimCount(_ShootAnimCount),
		WalkAnimCount(_WalkAnimCount){
	}
	int AttackAnimCount{};
	int HurtAnimCount{};
	int IdleAnimCount{};
	int ShootAnimCount{};
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
	int Level{};
	int MaxHp{};
	int ATK{};
	int SPD{};
};

class DungeonTile
{
public:
	class USpriteRenderer* SpriteRenderer = nullptr;
	TileType TileType = TileType::None;
	FTransform TileTrans{};
};


struct DungeonInfo {
	DungeonInfo(
		int _Width,
		int _Height,
		int _MaxFloor,
		const std::vector<std::string>&_Pokemons_In_Dongeon) :
		Width(_Width),
		Height(_Height),
		MaxFloor(_MaxFloor),
		Pokemons_In_Dongeon(_Pokemons_In_Dongeon) {
	}
	int MaxFloor{};
	int Width{};
	int Height{};
	std::vector<std::string> Pokemons_In_Dongeon;
};






