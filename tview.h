#pragma once

#include <functional>
#include <string>
#include "view.h"

using namespace std;

class tview : public view
{
public:
	tview();
	virtual void show();
	virtual void paint(const Rabbit& r);
	virtual void paint(const Snake& s);
	int get_row();
	int get_col();

private:
	int row;
	int col;

	static function<void(void)> onwinch;
	static void winch(int n);
	void draw_set_winsize();
	void draw_set_color(char color);
	void draw_default_color();
	void draw_string(int x, int y, string str);
	void draw_v_line(int x, int y, int len);
	void draw_g_line(int x, int y, int len);
	void draw_frame();
	void draw_go_to(int x, int y);
	void draw_clear_all();
};
