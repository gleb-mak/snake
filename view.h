#pragma once

#include "model.h"

class View
{
public:
	View(){}
	virtual void show(void) = 0;
	virtual void paint(const Rabbit& r) = 0;
	virtual void paint(const Snake& s) = 0;
	virtual void paint(const Coord& c, string obj, string color) = 0;
	virtual void clear(const Coord&c) = 0;
	virtual int get_col() = 0;
	virtual int get_row() = 0;
};
