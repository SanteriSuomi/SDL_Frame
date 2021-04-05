#pragma once

#include "CollisionComponent.h"

class CircleComponent : public CollisionComponent<CircleComponent> {
public:
	CircleComponent(class Actor *owner, int updateOrder, float radius);

	bool Intersects(CircleComponent &first, CircleComponent &second) override;

	float GetRadius() const {
		return radius;
	}
private:
	float radius;
};
