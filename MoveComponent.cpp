#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"

MoveComponent::MoveComponent(Actor *owner, int updateOrder) : Component(owner, updateOrder) {

}

void MoveComponent::Update(float delta) {
	if (!math::Compare<float>(forwardSpeed, 0)) {
		auto position = owner->GetPosition() + math::Vector2<float>::RotationToForward(owner->GetRotation()) * (forwardSpeed * delta);
		owner->SetPosition(position);
	}
	if (!math::Compare<float>(angularSpeed, 0)) {
		float rotation = owner->GetRotation() + (angularSpeed * delta);
		owner->SetRotation(rotation);
	}
}
