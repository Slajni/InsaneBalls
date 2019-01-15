#pragma once
#include "Modifier.h"
class FallingDeath :
	public Modifier
{
public:
	virtual char effect() override;
	FallingDeath(const sf::Texture & text, sf::RenderWindow * window, float speedy = 6.0);
	FallingDeath();
	~FallingDeath();
};

