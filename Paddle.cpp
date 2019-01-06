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
	this->position = sf::Mouse::getPosition(*this->gParentWindow());
	this->position.x = this->position.x - this->size.x / 2;
	this->position.y = 800 - this->size.y;
	this->changePosition(this->position.x, this->position.y);
}
