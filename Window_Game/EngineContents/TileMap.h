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

	void CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName);
	void SetTile(int _col, int _row, std::string_view _SpriteName);

protected:
	std::vector <std::vector<Tile>> Tiles;

private:
	

};

