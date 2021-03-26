#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(Game *game) : game(game) {
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
			break;
		}
	}
}

void Actor::RemoveComponent(Component *component) {
	auto it = std::find(components.begin(), components.end(), component);
	if (it != components.end()) {
		components.erase(it);
	}
}

Game* Actor::GetGame() {
	return game;
}

Actor::State Actor::GetState() const {
	return state;
}

void Actor::SetState(State s) {
	state = s;
}

Vector2<float> Actor::GetPosition() const {
	return position;
}

void Actor::SetPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

float Actor::GetScale() const {
	return scale;
}

void Actor::SetScale(float s) {
	scale = s;
}

float Actor::GetAngle() const {
	return angle;
}

void Actor::SetAngle(float a) {
	angle = a;
}
