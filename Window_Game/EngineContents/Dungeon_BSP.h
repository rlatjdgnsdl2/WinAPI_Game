#pragma once
#include "TileMap.h"
#include <EngineBase/EngineRandom.h>






//	설명:
class ADungeon_BSP : public ATileMap, public IPathFindData
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

	virtual void BeginPlay() override;
	void InitKeySet();

	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd()override;

	void Generate();
	void RoomClear();
	Room GetRoom(RoomNode* node) const;
	std::vector<FVector2D> GetRoomLocations() const { return RoomLocations; }

	FVector2D GetPotalLocation() const { return PotalLocation; }

	void NextFloor() { 
		CurFloor++; 
		if (CurFloor > MaxFloor) {
			CurFloor = 1;
		}
	}
	void ResetFloor() { CurFloor = 1; }
	int GetCurFloor() const { return CurFloor; }
	UEngineRandom Random;
protected:

private:
	RoomNode* root;

	std::vector<Room> Rooms;
	std::vector<FVector2D> RoomLocations;
	FVector2D PotalLocation;

	int CurFloor=1;
	int MaxFloor;

	

	//	던전생성과정
	void InitDungeon();
	void CreateNaturalFeatures();
	void Split(RoomNode* node);
	void CreateRooms(RoomNode* node);
	void ConnectRooms(RoomNode* node);
	void SetNaturally();
	void SetNextPotal();


	std::map<std::string, int > TileIndexForKey;

	bool IsMove(const FIntPoint& _Point) override;

};





