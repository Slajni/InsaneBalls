#include "Modifier.h"



Modifier::Modifier()
{
}

Modifier::Modifier(const sf::Texture & text, sf::RenderWindow * window, float speedy)
	:Movable(text, rand() % 601 + 100, -30, window, sf::Vector2f(0.0, speedy))
{

}

void Modifier::effect()
{
}

void Modifier::update()
{
	this->move(this->getDirections(), this->getSpeeds(), this->getMultipliers());
}


Modifier::~Modifier()
{
}
