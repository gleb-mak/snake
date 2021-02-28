#include <functional>
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include "tview.h"
#include <cstdio>

#define ESC "\033"

using namespace std;

function<void(void)> tview::onwinch;

tview::tview()
{
	draw_set_winsize();
	onwinch = bind(&tview::show, this);
	struct sigaction act;
	act.sa_handler = &tview::winch;
	act.sa_flags = SA_RESTART;
	sigaction(SIGWINCH, &act, 0);
}

void tview::draw_set_winsize()
{
	struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    col = win.ws_col;
    row = win.ws_row;
}

int tview::get_row()
{
	return row;	
}

int tview::get_col()
{
    return col;
}

void tview::winch(int n)
{
	onwinch();
}

void tview::draw_v_line(int x, int y, int len)
{
	draw_go_to(x, y);
	for (int i = y; i <= len + y; ++i)
	{
		draw_go_to(x, i);
		cout << "|";
	}
}

void tview::draw_g_line(int x, int y, int len)
{
	draw_go_to(x, y);
	for (int i = x; i <= len + x; ++i)
	{
		draw_go_to(i, y);
		cout << "-";
	}
}

void tview::draw_frame()
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

void tview::draw_string(int x, int y, string str)
{
	draw_go_to(x, y);
	cout << str;
}

void tview::draw_go_to(int x, int y)
{
	printf(ESC "[%d;%dH", y, x);
}

void tview::draw_clear_all()
{
	printf(ESC "[H");
	printf(ESC "[J");
}

void tview::draw_set_color(char color)
{
	switch (color)
	{
		case 'r':
			printf(ESC "[31;1m");
			break;
		case 'g':
			printf(ESC "[32;1m");
			break;
		case 'y':
			printf(ESC "[33;1m");
			break;
		case 'b':
			printf(ESC "[34;1m");
			break;
		default:
			break;
	}
}

void tview::draw_default_color()
{
	printf(ESC "[0m");
}

void tview::paint(const Rabbit& r)
{
	Coord c = r.get_coord();
	draw_string(c.x, c.y, "r");
}

void tview::paint(const Snake& s)
{

}

void tview::show()
{
	setbuf(stdout, NULL);
	draw_clear_all();
	draw_set_winsize();
	draw_frame();
	draw_set_color('y');
	draw_string(col / 2, row / 2, "SNAKE");
	draw_default_color();
}

