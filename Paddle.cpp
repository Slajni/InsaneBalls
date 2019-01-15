#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::Paddle(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2i size)
	:MapObject(text, 400, size.y, window), Steerable(window)
{
	this->size = size;
	this->update();
}


Paddle::~Paddle()
{
}

sf::Vector2i Paddle::steer()
{
	return sf::Mouse::getPosition(*gParentWindow());
}

void Paddle::update()
{
	sf::Vector2i curPos = steer();
	this->getPosition()->x = curPos.x - this->size.x / 2;
	this->getPosition()->y = 800 - this->size.y;
	this->changePosition(this->getPosition()->x, this->getPosition()->y);
}
