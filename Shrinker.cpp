#include "Shrinker.h"



char Shrinker::effect()
{
	Modifier::effect();
	return 's';
}

Shrinker::Shrinker(const sf::Texture & text, sf::RenderWindow * window, float speedy)
	:Modifier(text, window)
{
}

Shrinker::Shrinker()
{
}


Shrinker::~Shrinker()
{
}
