#include "Movable.h"



void Movable::negateDx()
{
	directions.x *= (-1);
}

void Movable::negateDy()
{
	directions.y *= (-1);
}

void Movable::setDy(float y)
{
	directions.y = y;
}

void Movable::setDx(float x)
{
	directions.x = x;
}

void Movable::deleteFromMap()
{
	this->changePosition(40, 1000);
}

sf::Vector2f Movable::getDirections()
{
	return this->directions;
}

sf::Vector2f Movable::getSpeeds()
{
	return this->speeds;
}

sf::Vector2f Movable::getMultipliers()
{
	return this->multipliers;
}

void Movable::move(sf::Vector2f dirs, sf::Vector2f velocities, sf::Vector2f mults)
{
	float xmove = directions.x * speeds.x * multipliers.x;
	float ymove = directions.y * speeds.y * multipliers.y;
	this->gSprite()->move(xmove, ymove);
	this->setPosition(this->getPosition()->x + xmove, this->getPosition()->y + ymove);
}

Movable::Movable()
{
}

Movable::Movable(const sf::Texture & text, int x, int y, sf::RenderWindow * window, sf::Vector2f velocities, sf::Vector2f dirs, sf::Vector2f mults)
	:MapObject(text,x,y,window)
{
	this->directions = dirs;
	this->speeds = velocities;
	this->multipliers = mults;
}




Movable::~Movable()
{
}

