#pragma once
#include <Windows.h>

class GameEngine
{
public:
	virtual ~GameEngine() = default;
	static  GameEngine* GetEngine();


protected:
	GameEngine();
	static  GameEngine* MainEngine;

private:
	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	virtual void Release();

};

