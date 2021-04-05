#pragma once

#include "Component.h"

class CollisionComponent : public Component {
public:
	CollisionComponent(class Actor *owner, int updateOrder);

	void Update(float delta) override;
	virtual bool Intersects(CollisionComponent *first, CollisionComponent *second);
};
