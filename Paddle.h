#pragma once
#include "MapObject.h"
class Paddle :
	public MapObject
{
private:

	sf::Vector2i size; // size of the paddle
	sf::Vector2i position; // current position on the map
public:
	Paddle();
	Paddle(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2i size);
	~Paddle();
	
	virtual void update() override;

};

