#include "gview.h"

Gview::Gview()
{
	window.create(sf::VideoMode(200, 200), "Game");
	while (window.isOpen())
    	{
			sf::Event event;
        	while (window.pollEvent(event))
        		{
            		if (event.type == sf::Event::Closed)
					window.close();
        		}
        Gview::show();

		// window.draw(rabsprite);
		window.display();
		//
    	}
}

Gview::~Gview()
{

}

void Gview::show()
{
	window.clear(sf::Color::White);
	draw_frame();
}

void Gview::draw_frame()
{
	
}


void Gview::paint(const Coord& r)
{

}

void Gview::paint(const DrawSnake& s)
{

}

void Gview::paint(const DrawUpdateSnake& s)
{

}

int Gview::get_row()
{

}

int Gview::get_col()
{

}

void Gview::ontimer(const timer_fn, int time)
{

}

void Gview::onkey(const key_fn)
{

}

void Gview::runloop()
{

}

void Gview::quit()
{

}
