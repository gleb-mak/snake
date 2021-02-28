#include <iostream>
#include "tview.h"
#include <string>
#include "view.h"
#include "model.h"

using namespace std;

int main() {
	tview v;
	Model m(&v);
	v.show();
	list<Rabbit> rabbits = m.get_rabbits();
	v.paint(rabbits.back());
	getchar();
	return 0;
}
