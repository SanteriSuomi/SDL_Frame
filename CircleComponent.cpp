#include "CircleComponent.h"

template<typename T>
CircleComponent<T>::CircleComponent(Actor *owner, int updateOrder, const Circle &circle) : CollisionComponent(owner, updateOrder), circle(circle) {

}

template<typename T>
bool CircleComponent<T>::Intersects(const Circle &first, const Circle &second) {
	return false;
}
