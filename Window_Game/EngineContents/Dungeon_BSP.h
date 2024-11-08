#pragma once
#include "TileMap.h"
#include <EngineBase/EngineRandom.h>





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

	Room getRoom(Node* node) const;
	void SetCurDungeonName(std::string_view _CurDungeonName)
	{
		CurDungeonName = _CurDungeonName;
	}
	std::vector<FVector2D> GetRoomLocations() const {
		return RoomLocations;
	}

	void CreateNaturalFeatures();

	FVector2D GetMapSize() 
	{
		return FVector2D(Width * 72, Height * 72);
	}







protected:

private:

	const int MIN_SIZE = 8;
	UEngineRandom Random;
	std::string CurDungeonName ="BeachCave";
	Node* root;
	int Width, Height;
	std::vector<FVector2D> RoomLocations;
	



	void InitDungeon();
	void CreateRooms(Node* node);
	void ConnectRooms(Node* node);
	void split(Node* node);
	void SetNaturally();



};





