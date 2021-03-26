#pragma once

#include <vector>
#include "Vector2.h"

class Actor {
public:
	enum class State {
		Active,
		Paused,
		Dead
	};

	explicit Actor(class Game *game);
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

	Vector2<float> GetPosition() const {
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

	float GetAngle() const {
		return scale;
	}

	void SetAngle(float a) {
		angle = a;
	}
private:
	class Game *game = nullptr;
	std::vector<Component *> components;
	State state = State::Active;
	Vector2<float> position = { 0.0F, 0.0F };
	float scale = 0.0F;
	float angle = 0.0F;
};
