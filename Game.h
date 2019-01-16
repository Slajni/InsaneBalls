#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include "MapObject.h"
#include "Paddle.h"
#include "Ball.h"
#include "Modifier.h"
#include "Movable.h"
#include "HollowBall.h"

class Game
{
private:

	sf::RenderWindow * mainWindow;
	sf::Texture gameTexture;
	sf::Vector2i * size;
	sf::Sprite * map;
	std::vector <MapObject*> objectsOnMap;
	std::vector <Movable*> movables;
	Paddle * paddle;
	HollowBall * hollowBall;
	std::vector <Ball*> balls;
	std::vector <Modifier*> modifiers;

	bool isCollide(sf::Sprite * s1, sf::Sprite * s2);
	void addMovable(Movable * obj);

	int lives = 100;

	sf::Clock extenderClock;
	sf::Clock shrinkerClock;

	bool shrinked = 0;
	bool extended = 0;

public:
	Game(sf::RenderWindow* window, std::string adress = "images/background.jpg");
	Game();
	~Game();


	void update();
	void addMapObject(MapObject * obj);
	void addBall(Ball * obj);
	void addPaddle(Paddle * obj);
	void addModifier(Modifier * obj);
	void addHollowBall(HollowBall * obj);
	int getLives();
	void addLive();
	void takeLifeAway();
	void updateMoves(); // this function is responsible for bouncing of items and deleting them after they reach bottom of the map
	void shrinkPaddle();
	void extendPaddle();
};

