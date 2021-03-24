#pragma once

#include "SDL.h"
#include "Constants.h"

class Game {
public:
	bool Initialize();
	void Loop();
	void Shutdown();
private:
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	bool isRunning = false;
	Uint32 ticksCount = 0;

	void Input(float delta);
	void Update(float delta);
	void Output(float delta);
	void CreateScene();
};
