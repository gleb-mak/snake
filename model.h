#pragma once

#include <ctime>
#include <iostream>
#include <list>

using namespace std;

class View;

struct Coord
{
	int x;
	int y;
};

class Rabbit
{
public:
	Rabbit(int x, int y);
	Coord get_coord() const;
private:
	Coord c;
};

enum Direction {LEFT, RIGHT, UP, DOWN};

class Snake
{
public:
	Snake();
	Snake(Coord begin, int len);
	list<Coord> get_body() const;
	Coord get_head() const;
	Direction get_direct() const;
private:
	list<Coord> body;
	Coord head;
	Direction direct;
};

class Model
{
public:
	Model(View* myview);
	list<Rabbit> get_rabbits();
	Snake get_snake();
private:
	View* view;
	list<Rabbit> rabbits; 
	Snake snake;
};
