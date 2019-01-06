#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
class Game
{
private:

	sf::RenderWindow * mainWindow;
	sf::Texture gameTexture;
	sf::Vector2i * size;
	sf::Sprite * map;

public:
	Game(sf::Vector2i dims, std::string adress);
	Game(sf::RenderWindow* window, std::string adress = "images/background.jpg");
	Game();
	~Game();


	void update();
};

