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

	void RoomLocationClear();
	void Generate(std::string_view _CurDungeonName);

	Room getRoom(Node* node) const;
	std::vector<FVector2D> GetRoomLocations() const { return RoomLocations; }
	void SetCurDungoenName(std::string_view _CurDungeonName) {
		CurDungeonName = _CurDungeonName;
	}

protected:

private:
	const int MIN_SIZE = 8;
	UEngineRandom Random;
	std::string CurDungeonName;
	Node* root;
	std::vector<FVector2D> RoomLocations;
	FVector2D PotalLocation;
	

	//	던전생성과정
	void InitDungeon();
	void CreateNaturalFeatures();
	void Split(Node* node);
	void CreateRooms(Node* node);
	void ConnectRooms(Node* node);
	void SetNaturally();
	
	void SetNextPotal();



};





