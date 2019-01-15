#include "FallingDeath.h"



char FallingDeath::effect()
{
	Modifier::effect();
	return 'd';
}

FallingDeath::FallingDeath(const sf::Texture & text, sf::RenderWindow * window, float speedy)
	:Modifier(text, window)
{
}

FallingDeath::FallingDeath()
{
}


FallingDeath::~FallingDeath()
{
}
