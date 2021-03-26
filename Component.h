#pragma once

class Component {
public:
	Component(class Actor *owner, int updateOrder = 100);
	virtual ~Component();
	virtual void Update(float delta);

	int GetUpdateOrder() const {
		return updateOrder;
	}
protected:
	class Actor *owner = nullptr;
	int updateOrder = 0;
};
