#pragma once

#include "Component.h"

template <typename T>
class CollisionComponent : public Component {
public:
	CollisionComponent(class Actor *owner, int updateOrder);

	virtual bool Intersects(const T &first, const T &second);
};
