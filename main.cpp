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
#include "FallingDeath.h"
#include "Menu.h"
#include "Extender.h"
#include "Shrinker.h"

int main()
{
	srand(time(NULL));

	bool start = 1;

	sf::RenderWindow menuWindow(sf::VideoMode(600, 600), "MENU");


	Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);

	while (menuWindow.isOpen())
	{
		sf::Event event;

		while (menuWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						menuWindow.close();
						break;
					case 1:
					{
						start = 0;
						menuWindow.close();
						break;
					}
					case 2:
						menuWindow.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				menuWindow.close();

				break;

			}
		}

		menuWindow.clear();

		menu.draw(menuWindow);
		menuWindow.display();
	}

	if (start)
	{

		sf::RenderWindow window(sf::VideoMode(800, 800), "Insane Balls");
		int framerate = 60;
		window.setFramerateLimit(framerate);
		window.setMouseCursorVisible(false);

		Game * game = new Game(&window);
		sf::Texture paddleText;
		paddleText.loadFromFile("images/paddle.png");
		sf::Texture ballText;
		ballText.loadFromFile("images/ball.png");
		sf::Texture liveText;
		liveText.loadFromFile("images/heart.png");
		sf::Texture deathText;
		deathText.loadFromFile("images/death.png");
		sf::Texture shrinker;
		shrinker.loadFromFile("images/paddleShrinker.png");
		sf::Texture extender;
		shrinker.loadFromFile("images/paddleExtender.png");

		Paddle * paddle = new Paddle(paddleText, &window, sf::Vector2i(90, 9));


		game->addPaddle(paddle);
		game->addBall(new Ball(ballText, &window, sf::Vector2f(4.0, 4.0)));
		game->addHollowBall(new HollowBall(ballText, &window));
		sf::Clock gameClock;
		sf::Clock clock;
		sf::Clock modifierClock;
		sf::Clock hardClock;
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
				game->addBall(new Ball(ballText, &window, sf::Vector2f((rand() % 50 + 10) / 10, (rand() % 50 + 10) / 10)));
				clock.restart();
			}
			if (modifierClock.getElapsedTime() > sf::seconds(5))
			{
				switch (rand() % 4 + 1)
				{
				case 1:
					game->addModifier(new FallingHealth(liveText, &window));
					break;
				case 2:
					game->addModifier(new FallingDeath(deathText, &window));
					break;
				case 3:
					game->addModifier(new Extender(extender, &window));
					break;
				case 4:
					game->addModifier(new Shrinker(shrinker, &window));
					break;
				}
				modifierClock.restart();
			}
			if (hardClock.getElapsedTime() > sf::seconds(60))
			{
				framerate += 10;
				window.setFramerateLimit(framerate);
				hardClock.restart();
			}
		}

		std::cout << "\nYou survived " << gameClock.getElapsedTime().asSeconds() << " seconds" << std::endl;
		std::cin.get();

	}

    return 0;
}