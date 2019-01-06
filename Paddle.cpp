#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::Paddle(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2i size)
	:MapObject(text, 400, size.y, window)
{
	this->size = size;
	this->update();
}


Paddle::~Paddle()
{
}

void Paddle::update()
{
	this->getPosition = sf::Mouse::getPosition(*this->gParentWindow());
	this->getPosition()->x = this->getPosition()->x - this->getPosition()->x / 2;
	this->getPosition()->y = 800 - this->size.y;
	this->changePosition(this->getPosition()->x, this->getPosition()->y);
}
