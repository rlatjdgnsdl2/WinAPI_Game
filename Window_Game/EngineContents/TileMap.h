#pragma once
#include <EngineCore/Actor.h>




//	Ό³Έν:
class ATileMap : public AActor
{

public:
	class Tile
	{
	public:
		class USpriteRenderer* SpriteRenderer = nullptr;
		TILETYPE TileType;
		FTransform TileTrans;
	};

	class DungeonData
	{
	public:
		std::string CurDungeonName;
		//	all tile Type
		std::vector<std::vector<TILETYPE>>AllTileTypes;
		//	room transform
		std::vector<FTransform> Rooms;
	};


	//	constrcuter, destructer
	ATileMap();
	virtual ~ATileMap();
	//	delete Function
	ATileMap(const 	ATileMap& _Other) = delete;
	ATileMap(ATileMap&& _Other) noexcept = delete;
	ATileMap& operator=(const 	ATileMap& _Other) = delete;
	ATileMap& operator=(ATileMap&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelChangeStart() override;


	void InitTileMap();
	void SetTile(int _col, int _row, std::string_view _TileType);

	void SetAllWall();
	void SetHallWay();
	void SetRoom();
	void SetBorderWall();
	void SetNaturally();
	void CheckTile();
	
	TILETYPE GetTileType(int _x, int _y);

	DungeonData* GetDungeonData() 
	{
		return &DungeonData;
	};

protected:
	std::vector <std::vector<Tile>> Tiles;
	void CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName);

private:
	DungeonData DungeonData;
	std::vector<std::vector<TILETYPE>>AllTileTypes;
	std::vector<FTransform> Rooms;


	bool IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms);

	std::vector<FIntPoint>AllGround;

	const int BoderSize = 5;
	FIntPoint DungeonSize = { 60,40 };
	FVector2D TileSize = { 72,72 };

	int testNumX = 0;
	int	testNumY = 0;

};

