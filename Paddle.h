#pragma once
#include "MapObject.h"
#include "Steerable.h"
class Paddle :
	public MapObject, public Steerable
{
private:

	sf::Vector2i size; // size of the paddle
public:
	Paddle();
	Paddle(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2i size);
	~Paddle();

	void shrinkSize();
	void extendSize();
	virtual sf::Vector2i steer() override;
	virtual void update() override;

};

