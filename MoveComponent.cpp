#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"

MoveComponent::MoveComponent(Actor *owner, int updateOrder) : Component(owner, updateOrder) {

}

void MoveComponent::Update(float delta) {
	if (!math::Compare<float>(angularSpeed, 0)) {
		float rotation = owner->GetRotation() + angularSpeed * delta;
		owner->SetRotation(rotation);
	}
	if (!math::Compare<float>(forwardSpeed, 0)) {
		math::Vector2<float> position = owner->GetPosition() * forwardSpeed * delta;
		owner->SetPosition(position);
	}
}
