#pragma once

#include "Component.h"

class MoveComponent : public Component {
public:
	MoveComponent(class Actor *owner, int updateOrder = 5);

	void Update(float delta) override;

	float GetForwardSpeed() const {
		return forwardSpeed;
	}

	void SetForwardSpeed(float speed) {
		forwardSpeed = speed;
	}

	float GetAngularSpeed() const {
		return angularSpeed;
	}

	void SetAngularSpeed(float speed) {
		angularSpeed = speed;
	}
private:
	float forwardSpeed = 0.0F;
	float angularSpeed = 0.0F;
};