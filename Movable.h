#pragma once
#include "MapObject.h"

class Movable :
	public MapObject
{
private:
	sf::Vector2f speeds;
	sf::Vector2f directions;
	sf::Vector2f multipliers;

public:

	void negateDx();
	void negateDy();
	void setDy(float y);
	void setDx(float x);

	sf::Vector2f getDirections();
	sf::Vector2f getSpeeds();
	sf::Vector2f getMultipliers();

	void move(sf::Vector2f dirs, sf::Vector2f velocities, sf::Vector2f mults);
	Movable();
	Movable(const sf::Texture & text, int x, int y, sf::RenderWindow * window, sf::Vector2f velocities, sf::Vector2f dirs = sf::Vector2f(1.0,1.0), sf::Vector2f mults = sf::Vector2f(1.0,1.0));

	~Movable();
};

