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
	std::string GetMinimapSpriteName(const std::string_view _Key) const { return MiniMapSpriteName.find(_Key.data())->second; }

	FVector2D GetPotalLocation() const { return PotalLocation; }
	FVector2D GetPotalTile() const { return PotalLocation / 72; }

	void NextFloor() { 
		CurFloor++; 
		if (CurFloor > MaxFloor) {
			CurFloor = 1;
		}
	}
	void ResetFloor() { CurFloor = 1; }
	int GetCurFloor() const { return CurFloor; }


	
protected:

private:
	UEngineRandom Random;
	RoomNode* root = nullptr;
	std::vector<Room> Rooms;
	std::vector<FVector2D> RoomLocations;
	FVector2D PotalLocation = FVector2D::ZERO;
	std::vector<class AItem*> Items;

	class AMiniMap* MiniMap;
	

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
	void SetMiniMap();
	void SetItems();

	std::map<std::string, int > TileIndexForKey;
	std::map<std::string, std::string> MiniMapSpriteName;

	bool IsMove(const FIntPoint& _Point) override;

};





