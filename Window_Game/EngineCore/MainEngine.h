#pragma once
#include <vector>
class MainEngine
{
private:
	MainEngine();
	static MainEngine* mainEngine;
	std::vector<class AAcotr*> actorVec;

	void BeginPlay();
	void Tick();
	/*void InputProcess();
	void PhysicsProcess();
	void RenderProcess();
	void SoundProcess();*/

};

