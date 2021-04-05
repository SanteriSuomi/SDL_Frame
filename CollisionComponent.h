#pragma once

#include "Component.h"

class CollisionComponent : public Component {
public:
	CollisionComponent(class Actor *owner, int updateOrder);

	void Update(float delta) override;
	virtual bool Intersect(CollisionComponent *first, CollisionComponent *second);
};
