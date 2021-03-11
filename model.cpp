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
	snake = Snake();
	//snake = Snake(begin, 10);
}

void Model::updatestate(Snake& s)
{
	view->paint(s.get_head(), "o", "y");
	s.push_cell(s.get_head());
	switch (s.get_direct())
	{
		case LEFT:
			s.inc_dec_head("inc", 'x');
			view->paint(s.get_head(), ">", "y");
			break;
		case RIGHT:
			s.inc_dec_head("dec", 'x');
			view->paint(s.get_head(), "<", "y");
			break;
		case UP:
			s.inc_dec_head("dec", 'y');
            view->paint(s.get_head(), "^", "y");
			break;
		case DOWN:
			s.inc_dec_head("inc", 'y');
            view->paint(s.get_head(), "v", "y");
			break;
	}
	view->clear(s.get_tail());
	s.erase_tail();
}

void Model::updatestate(list<Rabbit>& rab)
{

}

void Model::tick(int interval)
{
	while(1)
	{
		updatestate(snake);
		updatestate(rabbits);
		usleep(interval);
	}
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
	Coord c = {2, 2};
	for (int j = 0; j < 6; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			body.push_back(c);
			c.x++;
		}
		for (int i = 0; i < 3; ++i)
		{
			body.push_back(c);
			c.y++;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		body.push_back(c);
		c.x++;
	}
	head = c;
	direct = LEFT;
}

Snake::Snake(Coord begin, int len)
{
    for (int i = 0; i < len; ++i)
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

Coord Snake::get_tail() const
{
	list<Coord>::const_iterator it = body.begin();
	return *it;
}

Direction Snake::get_direct() const
{
	return direct;
}

void Snake::inc_dec_head(string flag, char obj)
{
	if (flag == "inc")
	{
		if (obj == 'x')
		{
			head.x++;
		}
		else if (obj == 'y')
		{
			head.y++;
		}
	}
	else if (flag == "dec")
	{
		if (obj == 'x')
        {
            head.x--;
        }
        else if (obj == 'y')
        {
            head.y--;
        }
	}
}

void Snake::push_cell(Coord c)
{
	body.push_back(c);
}

void Snake::erase_tail()
{
	list<Coord>::iterator it = body.begin();
	body.erase(it);
}
