#include "CollisionComponent.h"

template <typename T>
CollisionComponent<T>::CollisionComponent(Actor *owner, int updateOrder) : Component(owner, updateOrder) {

}

template <typename T>
bool CollisionComponent<T>::Intersects(const T &first, const T &second) {
	return false;
}
