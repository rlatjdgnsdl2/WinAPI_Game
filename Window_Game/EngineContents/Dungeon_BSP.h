#pragma once
#include "TileMap.h"

//	Ό³Έν:
class ADungeon_BSP : public ATileMap

{
public:
	//	constrcuter, destructer
	ADungeon_BSP(int width, int height) : width(width), height(height) {};
	virtual ~ADungeon_BSP();

	//	delete Function
	ADungeon_BSP(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP(ADungeon_BSP&& _Other) noexcept = delete;
	ADungeon_BSP& operator=(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP& operator=(ADungeon_BSP&& _Other) noexcept = delete;

	void generate() {}


protected:

private:
	int width, height;

};

