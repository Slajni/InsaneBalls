#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include "MapObject.h"
class Game
{
private:

	sf::RenderWindow * mainWindow;
	sf::Texture gameTexture;
	sf::Vector2i * size;
	sf::Sprite * map;
	std::vector <MapObject> objectsOnMap;

public:
	Game(sf::Vector2i dims, std::string adress);
	Game(sf::RenderWindow* window, std::string adress = "images/background.jpg");
	Game();
	~Game();


	void update();
	void addMapObject(MapObject & obj);
};

