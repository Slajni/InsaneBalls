#include "Ball.h"
#include <cstdlib>


Ball::Ball()
{
}

Ball::Ball(const sf::Texture & text, sf::RenderWindow * window, float speedx, float speedy)
	:MapObject(text,rand()%601 + 100,-30,window)
{
	this->speedx = speedx;
	this->speedy = speedy;
}

void Ball::update()
{
	this->move(speedx,speedy,this->getDxes().x,this->getDxes().y);
	this->getPosition()->x += this->getDxes().x * speedx;
	this->getPosition()->y += this->getDxes().y * speedy;
}


Ball::~Ball()
{
}
