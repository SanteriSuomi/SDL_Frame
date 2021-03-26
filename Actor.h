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

	class Game* GetGame();
	State GetState() const;
	void SetState(State state);
	Vector2<float> GetPosition() const;
	void SetPosition(float x, float y);
	float GetScale() const;
	void SetScale(float scale);
	float GetAngle() const;
	void SetAngle(float angle);
private:
	class Game *game = nullptr;
	std::vector<Component *> components;
	State state = State::Active;
	Vector2<float> position = { 0.0F, 0.0F };
	float scale = 0.0F;
	float angle = 0.0F;
};
