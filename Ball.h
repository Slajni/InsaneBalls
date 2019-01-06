#pragma once
#include "MapObject.h"
class Ball :
	public MapObject

{
private:

	float speedx, speedy;

public:
	Ball();
	Ball(const sf::Texture & text, sf::RenderWindow * window, float speedx, float speedy);

	virtual void update() override;

	~Ball();
};

