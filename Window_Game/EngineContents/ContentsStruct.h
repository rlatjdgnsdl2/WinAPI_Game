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
		WalkAnimCount(_WalkAnimCount) {
	}
	int AttackAnimCount{};
	int HurtAnimCount{};
	int IdleAnimCount{};
	int ShootAnimCount{};
	int WalkAnimCount{};
};

// 0레벨일때 포켓몬 기본 능력치 도감
struct PokemonInfo
{
	PokemonInfo() {}
	PokemonInfo(
		int _HP,
		int _ATK,
		int _STK,
		int _DEF,
		int _SPD) :
		HP(_HP),
		ATK(_ATK),
		STK(_STK),
		DEF(_DEF),
		SPD(_SPD) {
	}
	int HP{};
	int ATK{};
	int STK{};
	int DEF{};
	int SPD{};
};
// 포켓몬 능력치
class PokemonAbility {
public:
	PokemonAbility() {}
	void InitAbility(const PokemonInfo& _BasicAbility, int _Level) {
		MaxHP = _BasicAbility.HP + (_Level - 1) * 2;
		CurHP = MaxHP;
		ATK = _BasicAbility.ATK + (_Level - 1) * 2;
		CurATK = ATK;
		STK = _BasicAbility.STK + (_Level - 1) * 2;
		CurSTK = STK;
		DEF = _BasicAbility.DEF + (_Level - 1) * 2;
		CurDEF = DEF;
		SPD = _BasicAbility.SPD + (_Level - 1) * 2;
		CurSPD = SPD;
	}
	int MaxHP{};
	int CurHP{};
	int ATK{};
	int CurATK{};
	int STK{};
	int CurSTK{};
	int DEF{};
	int CurDEF{};
	int SPD{};
	int CurSPD{};
};
//	플레이어만 가지고 있는 데이터
class PlayerData {
public:
	PlayerData() {}
	PlayerData(int _Level) :Level(_Level) {}
	int Level{};
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
		int _MaxLevel,
		const std::vector<std::string>& _Pokemons_In_Dongeon) :
		Width(_Width),
		Height(_Height),
		MaxFloor(_MaxFloor),
		MaxLevel(_MaxLevel),
		Pokemons_In_Dongeon(_Pokemons_In_Dongeon) {
	}
	int Width{};
	int Height{};
	int MaxFloor{};
	int MaxLevel{};
	std::vector<std::string> Pokemons_In_Dongeon;
};






