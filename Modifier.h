#pragma once
#include "MapObject.h"
class Modifier :
	public MapObject
{
private:



public:
	Modifier();
	Modifier(const sf::Texture & text, sf::RenderWindow * window, float speedy = 8.0);
	
	//virtual void update() override;

	~Modifier();
};

