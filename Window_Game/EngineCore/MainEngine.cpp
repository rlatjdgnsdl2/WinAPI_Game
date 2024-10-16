#include "MainEngine.h"


MainEngine* MainEngine::mainEngine = nullptr;


void MainEngine::StartGame(App* _game)
{
	MainEngine Engine;
	mainEngine = &Engine;
	Engine.BeginPlay();
	_game->BeginPlay(mainEngine);

	while (Engine.isActive) {
		Engine.Tick();
	}
	Engine.End();
	
}
