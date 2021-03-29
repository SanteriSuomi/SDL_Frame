#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(Game *game) : game(game) {
	game->AddActor(this);
}

Actor::Actor(Game *game, State state, Vector2<float> position, float scale, float angle) : game(game), state(state), position(position),
scale(scale), angle(angle) {
	game->AddActor(this);
}

Actor::~Actor() {
	game->RemoveActor(this);
	while (!components.empty()){
		delete components.back();
	}
}

void Actor::Update(float delta) {
	if (state == State::Active) {
		UpdateActor(delta);
		UpdateComponents(delta);
	}
}

void Actor::UpdateActor(float delta) {

}

void Actor::UpdateComponents(float delta) const {
	for (const auto &c : components) {
		c->Update(delta);
	}
}

void Actor::AddComponent(Component *component) {
	for (auto it = components.begin(); it != components.end(); it++) {
		if (component->GetUpdateOrder() < (*it)->GetUpdateOrder()) {
			components.insert(it, component);
			return;
		}
	}
	components.emplace_back(component);
}

void Actor::RemoveComponent(Component *component) {
	auto it = std::find(components.begin(), components.end(), component);
	if (it != components.end()) {
		components.erase(it);
	}
}
