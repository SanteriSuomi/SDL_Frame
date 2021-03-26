#pragma once

#include "SDL.h"
#include <vector>

class Game {
public:
	bool Initialize();
	void Loop();
	void Shutdown();

	void AddActor(class Actor *actor);
	void RemoveActor(class Actor *actor);
private:
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	bool isRunning = false;
	Uint32 ticksCount = 0;

	bool updatingActors = false;
	std::vector<class Actor *> actors;
	std::vector<class Actor *> pendingActors;

	void Input(float delta);
	void Update(float delta);
	void Output(float delta);
	void CreateScene();
	void DeleteScene();
};
