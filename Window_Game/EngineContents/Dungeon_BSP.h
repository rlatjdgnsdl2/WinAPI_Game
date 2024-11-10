#pragma once
#include "TileMap.h"
#include <EngineBase/EngineRandom.h>





//	설명:
class ADungeon_BSP : public ATileMap

{
public:
	friend class ATurnManager;
	//	constrcuter, destructer
	ADungeon_BSP();
	virtual ~ADungeon_BSP();

	//	delete Function
	ADungeon_BSP(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP(ADungeon_BSP&& _Other) noexcept = delete;
	ADungeon_BSP& operator=(const ADungeon_BSP& _Other) = delete;
	ADungeon_BSP& operator=(ADungeon_BSP&& _Other) noexcept = delete;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;

	void Generate();

	Room getRoom(Node* node) const;
	std::vector<FVector2D> GetRoomLocations() const { return RoomLocations; }
	
	void SetDungeonData(std::string_view _DungeonName, int _Width, int _Height, int TrapCount);

protected:

private:
	const int MIN_SIZE = 8;
	UEngineRandom Random;
	std::string CurDungeonName = "BeachCave";
	Node* root;
	int Width = 60; 
	int Height = 40;
	std::vector<FVector2D> RoomLocations;
	FVector2D PotalLocation;
	

	//	던전생성과정
	void InitDungeon();
	void CreateNaturalFeatures();
	void split(Node* node);
	void CreateRooms(Node* node);
	void ConnectRooms(Node* node);
	void SetNaturally();
	
	void SetNextPotal();



};





