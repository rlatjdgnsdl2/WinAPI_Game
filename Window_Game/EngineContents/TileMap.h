#pragma once
#include <EngineCore/Actor.h>


enum class TileType {
	GROUND = 0,
	WALL,
	SOFTWALL
};

//	Ό³Έν:
class ATileMap : public AActor
{

public:
	class Tile
	{
	public:
		class USpriteRenderer* SpriteRenderer = nullptr;
		TileType TileType;
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

	FIntPoint GetTileCount() {
		return DungeonSize;
	}
	FVector2D GetTileLocation(int _x, int _y) {
		FVector2D TileLocation = Tiles[_y][_x].TileTrans.Location;
		return TileLocation;
	}
	class USpriteRenderer* GetSpriteRenderer(int _x, int _y) 
	{
		return Tiles[_y][_x].SpriteRenderer;
	}
	void CheckTile();
	void SetAllWall();

protected:

private:
	void CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName);
	std::vector <std::vector<Tile>> Tiles;
	FIntPoint DungeonSize = { 60,40 };
	FVector2D TileSize = { 72,72 };

	int testNumX = 0;
	int	testNumY = 0;


};

