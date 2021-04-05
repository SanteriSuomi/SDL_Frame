#include "PhysicsInputComponent.h"

PhysicsInputComponent::PhysicsInputComponent(Actor *owner, int updateOrder, float maxForwardSpeed, float maxAngularSpeed, float mass) 
	: PhysicsMoveComponent(owner, updateOrder, mass), maxForwardSpeed(maxForwardSpeed), maxAngularSpeed(maxAngularSpeed) {

}

void PhysicsInputComponent::Input(const uint8_t *keyState) {
	float fSpeed = 0.0F;
	if (keyState[forwardKey]) {
		fSpeed += maxForwardSpeed;
	}
	if (keyState[backKey]) {
		fSpeed -= maxForwardSpeed;
	}
	AddForce({ 0, fSpeed });

	float aSpeed = 0.0F;
	if (keyState[clockwiseKey]) {
		aSpeed += maxAngularSpeed;
	}
	if (keyState[counterClockwiseKey]) {
		aSpeed -= maxAngularSpeed;
	}
	SetAngularSpeed(aSpeed);
}
