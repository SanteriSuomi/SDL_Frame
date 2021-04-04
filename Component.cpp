#include "Component.h"
#include "Actor.h"

Component::Component(Actor *owner, int updateOrder) : owner(owner), updateOrder(updateOrder) {
	owner->AddComponent(this);
}

Component::~Component() {
	owner->RemoveComponent(this);
}

void Component::Update(float delta) {

}

void Component::Input(const uint8_t *keyState) {

}
