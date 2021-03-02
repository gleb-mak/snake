#pragma once

#include "model.h"

class View
{
public:
	View(){}
	virtual void show(void) = 0;
	virtual void paint(const Rabbit& r) = 0;
	virtual void paint(const Snake& s) = 0;
	virtual int get_col() = 0;
	virtual int get_row() = 0;
};
