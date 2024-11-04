#pragma once
#include <EngineCore/Actor.h>


enum class TileType {
	GROUND=0,
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
		class USpriteRenderer* TileMapRenderer = nullptr;
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

	void SetTile(int _col, int _row, std::string_view _TileType);
	void InitTileMap();
	void CheckTile();


protected:

private:
	class USpriteRenderer* CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName);
	std::vector <std::vector<Tile>> Tiles;
	std::string CurDungeonName = "BeachCave";
	int testNumX = 0;
	int	testNumY = 0;


};

