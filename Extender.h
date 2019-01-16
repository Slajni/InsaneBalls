#pragma once
#include "Modifier.h"
class Extender :
	public Modifier
{
public:
	virtual char effect() override;
	Extender(const sf::Texture & text, sf::RenderWindow * window, float speedy = 6.0);
	Extender();
	~Extender();
};

