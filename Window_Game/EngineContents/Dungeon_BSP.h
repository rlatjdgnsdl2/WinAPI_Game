#pragma once
#include "TileMap.h"
#include <EngineBase/EngineRandom.h>





//	Ό³Έν:
class ADungeon_BSP : public ATileMap

{
public:
	//	constrcuter, destructer
	ADungeon_BSP();
	virtual ~ADungeon_BSP();

	//	delete Function
	ADungeon_BSP(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP(ADungeon_BSP&& _Other) noexcept = delete;
	ADungeon_BSP& operator=(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP& operator=(ADungeon_BSP&& _Other) noexcept = delete;

	void LevelChangeStart()override;

	void Generate();

	Room getRoom(Node* node) const;
	void SetCurDungeonName(std::string_view _CurDungeonName) { CurDungeonName = _CurDungeonName; }
	std::vector<FVector2D> GetRoomLocations() const { return RoomLocations; }

protected:

private:

	const int MIN_SIZE = 8;
	UEngineRandom Random;

	std::string CurDungeonName = "BeachCave";
	Node* root;
	int Width, Height;
	std::vector<FVector2D> RoomLocations;

	void InitDungeon();
	void CreateNaturalFeatures();
	void split(Node* node);
	void CreateRooms(Node* node);
	void ConnectRooms(Node* node);
	void SetNaturally();



};





