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
	void LevelChangeStart() override;

	void CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName);
	void SetTile(int _col, int _row, std::string_view _SpriteName);


	void SetAllWall();
	void SetHallWay();
	void SetRoom();
	void SetBorderWall();
	void SetNaturally();
	
	TILETYPE GetTileType(int _x, int _y);

	

protected:
	std::vector <std::vector<Tile>> Tiles;

private:
	bool IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms);

	std::vector<FIntPoint>AllGround;


	int testNumX = 0;
	int	testNumY = 0;

};

