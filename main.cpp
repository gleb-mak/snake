#include <iostream>
#include <string>
#include "tview.h"
#include "view.h"
#include "model.h"

using namespace std;

int main() {
	Tview v;
	Model m(&v);
	v.show();
	v.paint(m.get_rabbits());
	v.paint(m.get_snake());
	getchar();
	return 0;
}
