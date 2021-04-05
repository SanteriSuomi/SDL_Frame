#include "CircleComponent.h"
#include "Actor.h"

#include "SDL.h"

CircleComponent::CircleComponent(Actor *owner, int updateOrder, float radius) : CollisionComponent(owner, updateOrder), radius(radius) {

}

bool CircleComponent::Intersect(CollisionComponent *first, CollisionComponent *second) {
	float distanceSquared = (first->GetOwner()->GetPosition() - second->GetOwner()->GetPosition()).LengthSquared();
	float radiiSquared = dynamic_cast<CircleComponent*>(first)->GetRadius() + dynamic_cast<CircleComponent*>(second)->GetRadius();
	radiiSquared *= radiiSquared;
	return distanceSquared <= radiiSquared;
}
