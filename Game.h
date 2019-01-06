#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include "MapObject.h"
#include "Paddle.h"
#include "Ball.h"

class Game
{
private:

	sf::RenderWindow * mainWindow;
	sf::Texture gameTexture;
	sf::Vector2i * size;
	sf::Sprite * map;
	std::vector <MapObject*> objectsOnMap;
	Paddle * paddle;
	std::vector <Ball*> balls;

	bool isCollide(sf::Sprite * s1, sf::Sprite * s2);

public:
	Game(sf::RenderWindow* window, std::string adress = "images/background.jpg");
	Game();
	~Game();


	void update();
	void addMapObject(MapObject * obj);
	void addBall(Ball * obj);
	void addPaddle(Paddle * obj);
	void updateMoves(); // this function is responsible for bouncing of items and deleting them after they reach bottom of the map
};

