#pragma once
#include <SFML/Graphics.hpp>


class Steerable
{
	sf::RenderWindow * parentWindow;
public:

	virtual sf::Vector2i steer();

	Steerable();
	Steerable(sf::RenderWindow * parent);
	~Steerable();
};

