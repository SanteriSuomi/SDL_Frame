#pragma once

#include "Component.h"

class MoveComponent : public Component {
public:
	MoveComponent(class Actor *owner, int updateOrder = 5);

	void Update(float delta) override;

	float GetAngularSpeed() const {
		return angularSpeed;
	}

	float GetForwardSpeed() const {
		return forwardSpeed;
	}

	void SetAngularSpeed(float speed) {
		angularSpeed = speed;
	}

	void SetForwardSpeed(float speed) {
		forwardSpeed = speed;
	}
private:
	float angularSpeed = 0.0F;
	float forwardSpeed = 0.0F;
};