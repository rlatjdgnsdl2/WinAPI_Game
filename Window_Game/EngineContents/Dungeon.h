#pragma once
#include <EngineCore/Actor.h>




//	Ό³Έν:
class ADungeon : AActor
{
public:
	
	//	constrcuter, destructer
	ADungeon();
	~ADungeon();

	//	delete Function
	ADungeon(const ADungeon& _Other) = delete;
	ADungeon(ADungeon&& _Other) noexcept = delete;
	ADungeon& operator=(const ADungeon& _Other) = delete;
	ADungeon& operator=(ADungeon&& _Other) noexcept = delete;

	void SetDungeonData(int _x, int _y, int _value);

protected:

private:
	std::vector<std::vector<int>> DungeonData;
	

};

