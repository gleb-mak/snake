#pragma once

#include "model.h"

class view
{
public:
	view(){}
	virtual void show(void) = 0;
	virtual void paint(const Rabbit& r) = 0;
	virtual void paint(const Snake& s) = 0;
};
