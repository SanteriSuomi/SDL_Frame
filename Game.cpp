#include "Game.h"

bool Game::Initialize() {
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (result == 0) {
		window = SDL_CreateWindow(
			"Space",
			300,
			175,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			0
		);
		if (!window) {
			SDL_Log("Failed to create window: %s", SDL_GetError());
			return false;
		}
		renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
		if (!renderer) {
			SDL_Log("Failed to create renderer: %s", SDL_GetError());
			return false;
		}
		isRunning = true;
		CreateScene();
		return true;
	}
	SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
	return false;
}

void Game::CreateScene() {

}

void Game::Loop() {
	while (isRunning) {
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + FRAME_TIME));
		float delta = (float)(SDL_GetTicks() - ticksCount) / 1000.0F;
		if (delta > MAX_DELTA_TIME) {
			delta = MAX_DELTA_TIME;
		}
		ticksCount = SDL_GetTicks();
		Input(delta);
		Update(delta);
		Output(delta);
	}
}

void Game::Input(float delta) {

}

void Game::Update(float delta) {

}

void Game::Output(float delta) {
	SDL_SetRenderDrawColor(
		renderer,
		105,
		162,
		255,
		255
	);
	SDL_RenderClear(renderer);
	// Draw...
	SDL_RenderPresent(renderer);
}

void Game::Shutdown() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
