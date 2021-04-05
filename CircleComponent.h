#pragma once

#include "CollisionComponent.h"
#include "Circle.h"

template<typename T>
class CircleComponent : public CollisionComponent<Circle> {
public:
	CircleComponent(class Actor *owner, int updateOrder, const Circle &circle);

	bool Intersects(const Circle &first, const Circle &second) override;
private:
	Circle circle;
};
