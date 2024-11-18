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
	
	virtual void LevelChangeEnd()override;

	void RoomClear();
	void Generate();
	Room GetRoom(Node* node) const;
	std::vector<FVector2D> GetRoomLocations() const { return RoomLocations; }

	int GetCurFloor() const { return CurFloor; }

protected:

private:
	const int MIN_SIZE = 8;
	UEngineRandom Random;
	Node* root;
	std::vector<FVector2D> RoomLocations;
	FVector2D PotalLocation;

	int CurFloor = 1;

	std::map<std::string,class USpriteRenderer*> UIRenderers;

	//	던전생성과정
	void InitDungeon();
	void CreateNaturalFeatures();
	void Split(Node* node);
	void CreateRooms(Node* node);
	void ConnectRooms(Node* node);
	void SetNaturally();
	void SetNextPotal();

	// IPathFindData을(를) 통해 상속됨
	bool IsMove(const FIntPoint& _Point) override;

};





