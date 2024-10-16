#pragma once
#include <vector>
class MainEngine
{
private:
	MainEngine();
	static MainEngine* mainEngine;
	std::vector<class AAcotr*> actorVec;

	static void StartGame(class App* _game);

	void BeginPlay();
	void Tick();
	/*void InputHandling();
	void WorldUpdate();
	void PhysicsUpdate();
	void RenderUpdate();*/
};

