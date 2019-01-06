#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "MapObject.h"
#include "Paddle.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Insane Balls");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	Game * game = new Game(&window);
	sf::Texture paddleText;
	paddleText.loadFromFile("images/paddle.png");


	game->addMapObject(new Paddle(paddleText,&window,sf::Vector2i(90,9)));

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