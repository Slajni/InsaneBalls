#pragma once
#include "MapObject.h"
#include "Movable.h"
class Modifier :
	public Movable
{
private:



public:
	Modifier();
	Modifier(const sf::Texture & text, sf::RenderWindow * window, float speedy = 8.0);
	
	//virtual void update() override;

	~Modifier();
};

