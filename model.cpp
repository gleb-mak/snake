#include "model.h"
#include "view.h"

Model::Model(View* myview)
{
	view = myview;
	int col = view->get_col();
	int row = view->get_row();
	srand(time(NULL));
	for (int i = 0; i < 5; ++i)
	{
		int x = rand() % (col - 2) + 1;
		int y = rand() % (row - 2) + 1;
		rabbits.push_back(Rabbit(x, y));
	}
	Coord begin;
	begin.x = col / 2;
	begin.y = row / 2;
	snake = Snake(begin, 10);
}

list<Rabbit> Model::get_rabbits()
{
	return rabbits;
}

Snake Model::get_snake()
{
	return snake;
}

Rabbit::Rabbit(int x, int y)
{
	c.x = x;
	c.y = y;
}

Coord Rabbit::get_coord() const
{
	return c;
}

Snake::Snake()
{
	Coord c = {1, 1};
	for (int i = 0; i < 4; ++i)
	{
		body.push_back(c);
		c.x++;
	}
	head = c;
	direct = LEFT;
}

Snake::Snake(Coord begin, int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        body.push_back(begin);
        begin.x++;
    }
    head = begin;
    direct = LEFT;
}


list<Coord> Snake::get_body() const
{
	return body;
}

Coord Snake::get_head() const
{
	return head;
}

Direction Snake::get_direct() const
{
	return direct;
}
