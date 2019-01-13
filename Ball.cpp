#include "Ball.h"
#include <cstdlib>
#include <iostream>

Ball::Ball()
{
}

Ball::Ball(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2f speeds)
	:Movable(text, rand() % 601 + 100, -30, window, speeds)
{
}

void Ball::update()
{
	this->move(this->getDirections(), this->getSpeeds(), this->getMultipliers());
}




Ball::~Ball()
{
	std::cout << "Ball deleted" << std::endl;
}
