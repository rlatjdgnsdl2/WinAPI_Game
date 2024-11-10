#pragma once



struct Room {
	int x, y, width, height;
	bool isValid() const {
		// ���� ��ȿ�Ϸ��� �ʺ�� ���̰� 0���� Ŀ�� ��
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
	unsigned int Hp;
	unsigned int Attack;
	unsigned int Defense;
	unsigned int Special_Attack;
	unsigned int Special_Defense;
	unsigned int Speed;
};

struct PokemonInfo
{
	std::string PokemonName;
	int AttackAnimCount;
	int HurtAnimCount;
	int IdleAnimCount;
	int WalkAnimCount;
};





