#pragma once
#include "MapObject.h"
#include "Movable.h"
class Ball :
	public Movable

{
private:

public:
	Ball();
	Ball(const sf::Texture & text, sf::RenderWindow * window, sf::Vector2f speeds);
	virtual void update() override;

	~Ball();
};

