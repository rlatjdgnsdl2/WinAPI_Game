#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATileMap : public AActor
{
public:
	//	constrcuter, destructer
	ATileMap();
	virtual ~ATileMap();

	//	delete Function
	ATileMap(const ATileMap& _Other) = delete;
	ATileMap(ATileMap&& _Other) noexcept = delete;
	ATileMap& operator=(const ATileMap& _Other) = delete;
	ATileMap& operator=(ATileMap&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	class USpriteRenderer* CreateTile(int _col, int _row, std::string_view _SpriteName);
	void SetTile(int _col, int _row, std::string_view _SpriteName);
	void CheckTile(std::string_view _SpriteName);


protected:

private:
	std::vector <std::vector<class USpriteRenderer*>> TileMap;
	int testNumX=0;
	int	testNumY=0;


};

