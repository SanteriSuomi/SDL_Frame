#pragma once

#include "SDL.h"
#include <vector>
#include <string>
#include <unordered_map>

class Game {
public:
	bool Initialize();
	void Loop();
	void Shutdown();

	void AddActor(class Actor *actor);
	void RemoveActor(class Actor *actor);

	void AddSprite(class SpriteComponent *sprite);
	void RemoveSprite(class SpriteComponent *sprite);
private:
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	bool isRunning = false;
	Uint32 ticksCount = 0;

	bool updatingActors = false;
	std::vector<class Actor *> actors;
	std::vector<class Actor *> pendingActors;

	std::unordered_map<const char *, SDL_Texture *> textureMap;
	std::vector<class SpriteComponent *> sprites;

	void Input();
	void Update();
	void Output();
	void CreateScene();
	void DeleteScene();

	SDL_Texture *LoadTexture(const char *fileName);
};
