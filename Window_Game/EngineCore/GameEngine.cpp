#include "GameEngine.h"

GameEngine* GameEngine::MainEngine = nullptr;

GameEngine* GameEngine::GetEngine()
{
	if (nullptr == MainEngine) {
		MainEngine = new GameEngine();
	}
	return MainEngine;
}
