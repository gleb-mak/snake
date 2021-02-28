#pragma once

#include <iostream>
#include <list>


using namespace std;

class view;

//extern int view::col;
//extern int view::row;

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

class Snake
{
private:
	list<Coord> body;
	enum direction {left, right, up, down};
};

class Model
{
public:
	Model(view* myview);
	list<Rabbit> get_rabbits();
//	void paint(const Rabbit& r);
private:
	view* myview;
	list<Rabbit> rabbits; 
	Snake snake;
};
