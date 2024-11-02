#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATileMap :public AActor
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
	void SetTile(int _row, int _col);

protected:

private:
	std::vector <std::vector<class USpriteRenderer*>> TileMap;
	std::map<std::string, int >a;
	
};

