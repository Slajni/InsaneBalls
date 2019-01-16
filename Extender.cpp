#include "Extender.h"



char Extender::effect()
{
	Modifier::effect();
	return 'e';
}

Extender::Extender(const sf::Texture & text, sf::RenderWindow * window, float speedy)
	:Modifier(text, window)
{
}

Extender::Extender()
{
}


Extender::~Extender()
{
}
