#pragma once
#include <EngineCore/Actor.h>


//	Ό³Έν:
class ADungeon : public AActor
{

public:
	//	constrcuter, destructer
	ADungeon();
	virtual ~ADungeon();

	//	delete Function
	ADungeon(const ADungeon& _Other) = delete;
	ADungeon(ADungeon&& _Other) noexcept = delete;
	ADungeon& operator=(const ADungeon& _Other) = delete;
	ADungeon& operator=(ADungeon&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	class USpriteRenderer* CreateTile(int _col, int _row, std::string_view _SpriteName);
	void SetTile(int _col, int _row, std::string_view _TileType);
	void CheckTile(std::string_view _SpriteName);
	void SetAllWall();
	void SetRandomSizeRoom();
	void SetRandomHallWay();

	
	
	


protected:

private:
	std::vector <std::vector<class USpriteRenderer*>> TileMap;
	std::string CurDungeonName = "BeachCave";
	int testNumX=0;
	int	testNumY=0;


};

