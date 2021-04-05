#include "CollisionComponent.h"
#include "Actor.h"
#include "Game.h"

CollisionComponent::CollisionComponent(class Actor *owner, int updateOrder) : Component(owner, updateOrder) {
	owner->GetGame()->AddCollision(this);
}

void CollisionComponent::Update(float delta) {
	for (const auto &c : *GetOwner()->GetGame()->GetCollisions()) {
		if (this != c 
			&& c->GetOwner()->GetState() != Actor::State::Dead 
			&& c->GetOwner()->GetState() != Actor::State::Paused
			&& Intersects(this, c)) {
			GetOwner()->SetState(Actor::State::Dead);
			SDL_Log("Intersection! (at: %d ticks)", SDL_GetTicks());
		}
	}
}

bool CollisionComponent::Intersects(CollisionComponent *first, CollisionComponent *second) {
	return false;
}
