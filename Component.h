#pragma once

#include <cstdint>

class Component {
public:
	Component(class Actor *owner, int updateOrder = 100);
	virtual ~Component();
	virtual void Update(float delta);
	virtual void Input(const uint8_t *state);

	int GetUpdateOrder() const {
		return updateOrder;
	}
protected:
	class Actor *owner = nullptr;
	int updateOrder = 0;
};
