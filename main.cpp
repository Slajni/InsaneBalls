#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "MapObject.h"
using namespace sf;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Insane Balls");
	window.setFramerateLimit(60);

	Game * game = new Game(&window);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
		
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		game->update();
    }

    return 0;
}