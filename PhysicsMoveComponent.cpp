#include "PhysicsMoveComponent.h"
#include "Actor.h"

PhysicsMoveComponent::PhysicsMoveComponent(Actor *owner, int updateOrder, float mass) 
	: Component(owner, updateOrder), mass(mass) {

}

void PhysicsMoveComponent::Update(float delta) {
	if (!force.Empty()) {
		force /= mass;
		auto acceleration = force;
		velocity += acceleration * delta;
		owner->SetPosition(owner->GetPosition() + velocity * delta);
		force = { 0, 0 };
		velocity = { 0, 0 };
	}
	if (!math::Compare<float>(angularSpeed, 0)) {
		float rotation = owner->GetRotation() + (angularSpeed * delta);
		owner->SetRotation(rotation);
	}
}
