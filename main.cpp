#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "Game.h"
#include "MapObject.h"
#include "Paddle.h"
#include "Ball.h"
#include "Modifier.h"
#include "FallingHealth.h"

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 800), "Insane Balls");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	Game * game = new Game(&window);
	sf::Texture paddleText;
	paddleText.loadFromFile("images/paddle.png");
	sf::Texture ballText;
	ballText.loadFromFile("images/ball.png");
	sf::Texture liveText;
	liveText.loadFromFile("images/heart.png");

	Paddle * paddle = new Paddle(paddleText, &window, sf::Vector2i(90, 9));


	game->addPaddle(paddle);
	game->addBall(new Ball(ballText, &window, sf::Vector2f(4.0, 4.0)));
	game->addModifier(new FallingHealth(liveText,&window));

	sf::Clock clock;
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
		if (game->getLives() < 1)
		{
			std::cout << "You lost" << std::endl;
			window.close();
		}
		if (clock.getElapsedTime() > sf::seconds(10))
		{
			game->addBall(new Ball(ballText, &window, sf::Vector2f((rand()%50 + 10)/10, (rand() % 50 + 10) / 10)));
			clock.restart();
		}
    }
	

	std::cin.get();
    return 0;
}