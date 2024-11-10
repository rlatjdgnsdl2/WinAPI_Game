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



struct PokemonData 
{
	CampType CurCamp;
	float CurDuration;
	DIR CurDir;
	FVector2D StartLocation;
	FVector2D TargetLocation;
	SkillType CurSkillType;
	unsigned int Hp;
	unsigned int Attack;
	unsigned int Defense;
	unsigned int Special_Attack;
	unsigned int Special_Defense;
};

struct PokemonInfo
{
	std::string PokemonName;
	int AttackAnimCount;
	int HurtAnimCount;
	int IdleAnimCount;
	int WalkAnimCount;
};





