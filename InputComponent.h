#pragma once

#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public MoveComponent {
public:
	InputComponent(Actor *owner, int updateOrder, float maxForwardSpeed, float maxAngularSpeed);

	void Input(const uint8_t *keyState) override;

	float GetMaxForwardSpeed() const {
		return maxForwardSpeed;
	}

	void SetMaxForwardSpeed(float speed) {
		maxForwardSpeed = speed;
	}

	float GetMaxAngularSpeed() const {
		return maxAngularSpeed;
	}

	void SetMaxAngularSpeed(float speed) {
		maxAngularSpeed = speed;
	}

	void SetKeys(int fKey, int bKey, int cKey, int ccKey) {
		forwardKey = fKey;
		backKey = bKey;
		clockwiseKey = cKey;
		counterClockwiseKey = ccKey;
	}
private:
	float maxForwardSpeed = 0.0F;
	float maxAngularSpeed = 0.0F;

	int forwardKey = 0;
	int backKey = 0;
	int clockwiseKey = 0;
	int counterClockwiseKey = 0;
};