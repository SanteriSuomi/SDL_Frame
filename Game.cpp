#include "Game.h"
#include "Actor.h"
#include "Constants.h"
#include "SDL_image.h"
#include "SpriteComponent.h"

bool Game::Initialize() {
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (result == 0) {
		window = SDL_CreateWindow(
			"Frame",
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
		if (IMG_Init(IMG_INIT_PNG) == 0) {
			SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
			return false;
		}
		isRunning = true;
		ticksCount = SDL_GetTicks();
		CreateScene();
		return true;
	}
	SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
	return false;
}

void Game::CreateScene() {

}

void Game::DeleteScene() {

}

void Game::Loop() {
	while (isRunning) {
		Input();
		Update();
		Output();
	}
}

void Game::Input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
		}
	}
	auto state = SDL_GetKeyboardState(nullptr);
	if (state[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}
}

void Game::Update() {
	// Advance frames and calculate tick count
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + FRAME_TIME));
	float delta = (float)(SDL_GetTicks() - ticksCount) / 1000.0F;
	if (delta > MAX_DELTA_TIME) {
		delta = MAX_DELTA_TIME;
	}
	ticksCount = SDL_GetTicks();

	// Update actors
	updatingActors = true;
	for (const auto &a : actors) {
		a->Update(delta);
	}
	updatingActors = false;

	// Move any pending actors to actors
	for (const auto &pending : pendingActors) {
		actors.emplace_back(pending);
	}
	pendingActors.clear();

	// Remove dead actors
	std::vector<Actor*> deadActors;
	for (const auto &a : actors) {
		if (a->GetState() == Actor::State::Dead) {
			deadActors.emplace_back(a);
		}
	}
	for (const auto &a : deadActors) {
		delete a;
	}
}

void Game::Output() {
	SDL_SetRenderDrawColor(
		renderer,
		105,
		162,
		255,
		255
	);
	SDL_RenderClear(renderer);
	for (const auto &s : sprites) {
		s->Draw(renderer);
	}
	SDL_RenderPresent(renderer);
}

void Game::Shutdown() {
	IMG_Quit();
	DeleteScene();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::AddActor(Actor *actor) {
	if (updatingActors) {
		pendingActors.emplace_back(actor);
	} else {
		actors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor *actor) {
	auto it = std::find(pendingActors.begin(), pendingActors.end(), actor);
	if (it != pendingActors.end()) {
		std::iter_swap(it, pendingActors.end() - 1);
		pendingActors.pop_back();
	}
	it = std::find(actors.begin(), actors.end(), actor);
	if (it != actors.end()) {
		std::iter_swap(it, actors.end() - 1);
		actors.pop_back();
	}
}

void Game::AddSprite(SpriteComponent *sprite) {
	for (auto it = sprites.begin(); it != sprites.end(); it++) {
		if (sprite->GetDrawOrder() < (*it)->GetDrawOrder()) {
			sprites.insert(it, sprite);
			return;
		}
	}
	sprites.emplace_back(sprite);
}

void Game::RemoveSprite(SpriteComponent *sprite) {
	auto it = std::find(sprites.begin(), sprites.end(), sprite);
	sprites.erase(it);
}

SDL_Texture *Game::LoadTexture(const char *fileName) {
	SDL_Texture *texture = nullptr;
	auto it = textureMap.find(fileName);
	if (it != textureMap.end()) {
		texture = it->second;
	} else {
		auto surface = IMG_Load(fileName);
		if (!surface) {
			SDL_Log("Failed to load texture file: %s", fileName);
			return nullptr;
		}
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		if (!texture) {
			SDL_Log("Failed to convert surface to texture: %s", fileName);
			return nullptr;
		}
		textureMap[fileName] = texture;
	}
	return texture;
}
