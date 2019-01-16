#pragma once
#include "Modifier.h"
class Shrinker :
	public Modifier
{
public:
	virtual char effect() override;
	Shrinker(const sf::Texture & text, sf::RenderWindow * window, float speedy = 6.0);
	Shrinker();
	~Shrinker();
};

