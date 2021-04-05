#include "CircleComponent.h"
#include "Actor.h"

CircleComponent::CircleComponent(Actor *owner, int updateOrder, float radius) : CollisionComponent(owner, updateOrder), radius(radius) {

}

bool CircleComponent::Intersects(CircleComponent &first, CircleComponent &second) {
	auto distanceSquared = (first.GetOwner()->GetPosition() - second.GetOwner()->GetPosition()).LengthSquared();
	float radiiSquared = first.GetRadius() + second.GetRadius();
	radiiSquared *= radiiSquared;
	return distanceSquared <= radiiSquared;
}
