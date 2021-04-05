#include "CollisionComponent.h"
#include "CircleComponent.h"

CollisionComponent<CircleComponent>::CollisionComponent(Actor *owner, int updateOrder) : Component(owner, updateOrder) {

}

template<typename T>
void CollisionComponent<T>::Update(float delta) {

}

template<typename T>
bool CollisionComponent<T>::Intersects(T &first, T &second) {
	return false;
}
