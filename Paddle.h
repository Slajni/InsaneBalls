#pragma once
#include "MapObject.h"
class Paddle :
	public MapObject
{
private:

	sf::Vector2i size; // size of the paddle
public:
	Paddle();
	Paddle(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2i size);
	~Paddle();
	
	virtual void update() override;

};

