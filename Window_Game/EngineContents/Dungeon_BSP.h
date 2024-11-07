#pragma once
#include "TileMap.h"





//	Ό³Έν:
class ADungeon_BSP : public ATileMap

{
public:
	//	constrcuter, destructer
	ADungeon_BSP(int _width = 60, int _height = 40);
	virtual ~ADungeon_BSP();

	//	delete Function
	ADungeon_BSP(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP(ADungeon_BSP&& _Other) noexcept = delete;
	ADungeon_BSP& operator=(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP& operator=(ADungeon_BSP&& _Other) noexcept = delete;

	void LevelChangeStart()override;

	void Generate();

	Room getRoom(Node* node) {
		if (node->isLeaf()) return node->room;
		if (node->left) return getRoom(node->left);
		if (node->right) return getRoom(node->right);
		return node->room;
	}
	void SetCurDungeonName(std::string_view _CurDungeonName)
	{
		CurDungeonName = _CurDungeonName;
	}



protected:

private:
	std::string CurDungeonName;
	const int MIN_SIZE = 10;
	const int MAX_SIZE = 20;
	Node* root;
	int width, height;

	void InitDungeon();
	void CreateRooms(Node* node);
	void ConnectRooms(Node* node);
	bool split(Node* node);


};





