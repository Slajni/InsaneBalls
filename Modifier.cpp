#include "Modifier.h"



Modifier::Modifier()
{
}

Modifier::Modifier(const sf::Texture & text, sf::RenderWindow * window, float speedy)
{
	this->setDx(0.0);
	this->setDy(speedy);
}


Modifier::~Modifier()
{
}
