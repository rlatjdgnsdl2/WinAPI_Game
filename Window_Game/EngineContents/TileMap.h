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

	void CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName, int _Index);
	void SetTile(int _x, int _y, std::string_view _SpriteName, int _Index);

	TileType GetTileType(int _x, int _y)const 
	{
		return Tiles[_y][_x].TileType;
	}
	void SetTileType(int _x, int _y, TileType _TileType)
	{
		Tiles[_y][_x].TileType = _TileType;
	}

protected:
	std::vector <std::vector<Tile>> Tiles;

private:
	

};

