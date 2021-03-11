#include "tview.h"

#define ESC "\033"

using namespace std;

function<void(void)> Tview::onwinch;

Tview::Tview()
{
	draw_set_winsize();
	onwinch = bind(&Tview::show, this);
	signal(SIGWINCH, Tview::winch);
}

void Tview::draw_set_winsize()
{
	struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    col = win.ws_col;
    row = win.ws_row;
}

int Tview::get_row()
{
	return row;	
}

int Tview::get_col()
{
    return col;
}

void Tview::winch(int n)
{
	onwinch();
}

void Tview::draw_v_line(int x, int y, int len)
{
	draw_go_to(x, y);
	for (int i = y; i <= len + y; ++i)
	{
		draw_go_to(x, i);
		cout << "|";
	}
}

void Tview::draw_g_line(int x, int y, int len)
{
	draw_go_to(x, y);
	for (int i = x; i <= len + x; ++i)
	{
		draw_go_to(i, y);
		cout << "-";
	}
}

void Tview::draw_frame()
{
    draw_v_line(0, 0, row);
    draw_v_line(col, 0, row);
	draw_g_line(0, 0, col);
	draw_g_line(0, row, col);
    draw_string(0, 0, "+");
    draw_string(col, 0, "+");
    draw_string(col, row, "+");
    draw_string(0, row, "+");
}

void Tview::draw_string(int x, int y, string str)
{
	draw_go_to(x, y);
	cout << str;
}

void Tview::draw_go_to(int x, int y)
{
	printf(ESC "[%d;%dH", y, x);
}

void Tview::draw_clear_all()
{
	printf(ESC "[H");
	printf(ESC "[J");
}

void Tview::draw_set_color(string color)
{
	if (color == "r")
	{
		printf(ESC "[31;1m");
	}
	else if (color == "green")
	{
		printf(ESC "[32;1m");
	}
    else if (color == "y")
    {
		printf(ESC "[33;1m");
    }
    else if (color == "b")
    {
		printf(ESC "[34;1m");
    }
    else if (color == "gray")
    {
		printf(ESC "[30;1m");
    }
}

void Tview::draw_default_color()
{
	printf(ESC "[0m");
}

void Tview::paint(const Rabbit& rabbit)
{
	Coord c = rabbit.get_coord();
	draw_set_color("b");
	draw_string(c.x, c.y, "*");
}

void Tview::paint(const list<Rabbit>& rabbits)
{
	for (Rabbit item : rabbits)
	{
		paint(item);
	}
}

void Tview::paint(const Snake& snake)
{
	draw_set_color("y");
	draw_string(snake.get_tail().x, snake.get_tail().y, "o");
	for (Coord c : snake.get_body())
	{
		draw_string(c.x, c.y, "o");
	}
	Coord head = snake.get_head();
	switch(snake.get_direct())
	{
		case LEFT:
			draw_string(head.x, head.y, ">");
			break;
		case RIGHT:
			draw_string(head.x, head.y, "<");
			break;
		case UP:
			draw_string(head.x, head.y, "^");
			break;
		case DOWN:
			draw_string(head.x, head.y, "v");
			break;
	}
	draw_default_color();
}

void Tview::paint(const Coord& c, string obj, string color)
{
	draw_set_color(color);
	draw_string(c.x, c.y, obj);
	draw_default_color();
}

void Tview::clear(const Coord& c)
{
	draw_string(c.x, c.y, " ");
}

void repaint(const Snake& snake)
{

}

void Tview::show()
{
	setbuf(stdout, NULL);
	draw_clear_all();
	draw_set_winsize();
	draw_frame();
}
