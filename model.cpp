#include "model.h"

Model::Model(view* thisview)
{
	myview = thisview;
	int col = myview->get_col();
	int row = myview->get_row();
	int x = rand() % (col - 2) + 1;
	int y = rand() % (row - 2) + 1;
	rabbits.push_back(Rabbit(10, 20));
}

list<Rabbit> Model::get_rabbits()
{
	return rabbits;
}

Coord Rabbit::get_coord() const
{
	return c;
}

Rabbit::Rabbit(int x, int y)
{
	c.x = x;
	c.y = y;
}
