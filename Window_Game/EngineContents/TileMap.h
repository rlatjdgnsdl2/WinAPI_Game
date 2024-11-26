#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/PathFindAstar.h>





//	Ό³Έν:
class ATileMap : public AActor
{

public:
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
	const std::vector<std::vector<DungeonTile>>& GetTiles()const
	{
		return Tiles;
	}
	const DungeonTile& GetTile(int _x, int _y)const
	{
		return Tiles[_y][_x];
	}
	


	bool IsOver(const FIntPoint& _FIntPoint) {
		if (0 > _FIntPoint.X) {
			return true;
		}
		if (0 > _FIntPoint.Y) {
			return true;
		}
		if ( Width < _FIntPoint.X) {
			return true;
		}
		if (Height < _FIntPoint.Y) {
			return true;
		}
		return false;

	}

protected:
	std::vector <std::vector<DungeonTile>> Tiles;
	const int Width = 60;
	const int Height = 40;
	

private:
	
	

};

