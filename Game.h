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
	std::vector <MapObject*> objectsOnMap;

public:
	Game(sf::RenderWindow* window, std::string adress = "images/background.jpg");
	Game();
	~Game();


	void update();
	void addMapObject(MapObject * obj);
	void updateMoves(); // this function is responsible for bouncing of items and deleting them after they reach bottom of the map
};

