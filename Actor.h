#pragma once

#include <vector>
#include "Math.h"

class Actor {
public:
	enum class State {
		Active,
		Paused,
		Dead
	};

	explicit Actor(class Game *game);
	explicit Actor(class Game *game, State state, math::Vector2<float> position, float scale, float angle);
	virtual ~Actor();

	void Update(float delta);
	void UpdateComponents(float delta) const;
	virtual void UpdateActor(float delta);

	void AddComponent(class Component *component);
	void RemoveComponent(class Component *component);

	class Game *GetGame() {
		return game;
	}

	State GetState() const {
		return state;
	}

	void SetState(State s) {
		state = s;
	}

	math::Vector2<float> GetPosition() const {
		return position;
	}

	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}

	float GetScale() const {
		return scale;
	}

	void SetScale(float s) {
		scale = s;
	}

	float GetRotation() const {
		return rotation;
	}

	void SetRotation(float rot) {
		rotation = rot;
	}

private:
	class Game *game = nullptr;
	std::vector<Component *> components;
	State state = State::Active;
	math::Vector2<float> position = { 0.0F, 0.0F };
	float scale = 0.0F;
	float rotation = 0.0F;
};
