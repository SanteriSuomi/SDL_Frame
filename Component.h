#pragma once


class Component {
public:
	Component(class Actor *owner, int updateOrder = 100);
	virtual ~Component();
	virtual void Update(float delta);

	int GetUpdateOrder() const;
private:
	Actor *owner;
	int updateOrder;
};
