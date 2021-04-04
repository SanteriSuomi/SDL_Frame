#include "InputComponent.h"

InputComponent::InputComponent(Actor *owner, int updateOrder, float maxForwardSpeed, float maxAngularSpeed) 
	: MoveComponent(owner, updateOrder), maxForwardSpeed(maxForwardSpeed), maxAngularSpeed(maxAngularSpeed) {

}

void InputComponent::Input(const uint8_t *keyState) {
	float fSpeed = 0.0F;
	if (keyState[forwardKey]) {
		fSpeed += maxForwardSpeed;
	}
	if (keyState[backKey]) {
		fSpeed -= maxForwardSpeed;
	}
	SetForwardSpeed(fSpeed);

	float aSpeed = 0.0F;
	if (keyState[clockwiseKey]) {
		aSpeed += maxAngularSpeed;
	}
	if (keyState[counterClockwiseKey]) {
		aSpeed -= maxAngularSpeed;
	}
	SetAngularSpeed(aSpeed);
}
