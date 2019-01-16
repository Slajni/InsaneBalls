#include "HollowBall.h"



HollowBall::HollowBall()
{
}

HollowBall::HollowBall(const sf::Texture & text, sf::RenderWindow * window)
	:Steerable(window), MapObject(text,400,400,window)
{
	this->gSprite()->setColor(sf::Color::Red);
}


HollowBall::~HollowBall()
{
}

sf::Vector2i HollowBall::steer()
{
	sf::Vector2i * pos = this->getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if(pos->x <=782)
			pos->x += 6;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if (pos->x >= 6)
			pos->x -= 6;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (pos->y >= 6)
			pos->y -= 6;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (pos->y <= 782)
			pos->y += 6;

	return *pos;
	
}

void HollowBall::update()
{
	steer();
	this->changePosition(this->getPosition()->x, this->getPosition()->y);
}
