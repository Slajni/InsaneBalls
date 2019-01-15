#include "Steerable.h"



sf::Vector2i Steerable::steer()
{
	return sf::Vector2i();
}

Steerable::Steerable()
{
}

Steerable::Steerable(sf::RenderWindow * parent)
{
	parentWindow = parent;
}


Steerable::~Steerable()
{
}

