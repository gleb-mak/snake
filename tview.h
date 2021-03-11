#pragma once

#include <string>
#include <cstdio>
#include <functional>
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include "view.h"

using namespace std;

class Tview : public View
{
public:
	Tview();
	void show();
	void paint(const Rabbit& rabbit);
	void paint(const list<Rabbit>& rabbits);
	void paint(const Snake& snake);
	void paint(const Coord& c, string obj, string color);
	void clear(const Coord& c);
	int get_row();
	int get_col();

private:
	int row;
	int col;

	static function<void(void)> onwinch;
	static void winch(int n);
	void draw_set_winsize();
	void draw_set_color(string color);
	void draw_default_color();
	void draw_string(int x, int y, string str);
	void draw_v_line(int x, int y, int len);
	void draw_g_line(int x, int y, int len);
	void draw_frame();
	void draw_go_to(int x, int y);
	void draw_clear_all();
};
