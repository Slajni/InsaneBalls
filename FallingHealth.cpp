#include "FallingHealth.h"



char FallingHealth::effect()
{
	Modifier::effect();
	return 'h';
}

FallingHealth::FallingHealth()
{
}

FallingHealth::FallingHealth(const sf::Texture & text, sf::RenderWindow * window, float speedy)
	:Modifier(text,window)
{

}


FallingHealth::~FallingHealth()
{
}
