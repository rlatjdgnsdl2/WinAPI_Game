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
	void InitTileMap();
	void SetTile(int _col, int _row, std::string_view _TileType);

	void SetAllWall();
	void SetHallWay();
	void SetRoom();
	void SetBorderWall();
	void SetNaturally();
	void CheckTile();
	
	static TILETYPE GetTileType(int _x, int _y);


	static std::vector<std::vector<TILETYPE>>AllTileTypes;
	static std::vector<FTransform> Rooms;
protected:

private:
	void CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName);
	std::vector <std::vector<Tile>> Tiles;
	std::vector<FIntPoint>AllGround;
	bool IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms);

	const int BoderSize = 5;
	FIntPoint DungeonSize = { 60,40 };
	FVector2D TileSize = { 72,72 };

	int testNumX = 0;
	int	testNumY = 0;


};

