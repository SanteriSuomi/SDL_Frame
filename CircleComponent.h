#pragma once

#include "CollisionComponent.h"

class CircleComponent : public CollisionComponent {
public:
	CircleComponent(class Actor *owner, int updateOrder, float radius);

	bool Intersects(CollisionComponent *first, CollisionComponent *second) override;

	float GetRadius() const {
		return radius;
	}
private:
	float radius;
};
