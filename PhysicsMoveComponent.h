#pragma once

#include "Component.h"
#include "Math.h"
#include <vector>

class PhysicsMoveComponent : public Component {
public:
	PhysicsMoveComponent(Actor *owner, int updateOrder, float mass);

	void Update(float delta) override;

	void AddForce(const math::Vector2<float> &f) {
		force += f;
	}

	float GetMass() const {
		return mass;
	}

	void SetMass(float m) {
		mass = m;
	}

	math::Vector2<float> GetVelocity() {
		return velocity;
	}

	void SetVelocity(const math::Vector2<float> &v) {
		velocity = v;
	}

	float GetAngularSpeed() const {
		return angularSpeed;
	}

	void SetAngularSpeed(float speed) {
		angularSpeed = speed;
	}
private:
	float mass = 0.0F;
	float angularSpeed = 0.0F;
	math::Vector2<float> force = { 0, 0 };
	math::Vector2<float> velocity = { 0, 0 };
};