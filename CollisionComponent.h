#pragma once

#include "Component.h"

template <typename T>
class CollisionComponent : public Component {
public:
	CollisionComponent(class Actor *owner, int updateOrder);

	void Update(float delta) override;

	virtual bool Intersects(T &first, T &second);
};