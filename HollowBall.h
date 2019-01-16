#pragma once
#include "Steerable.h"
#include "MapObject.h"

class HollowBall
	:public Steerable, public MapObject
{
public:
	HollowBall();
	HollowBall(const sf::Texture & text, sf::RenderWindow * window);
	~HollowBall();

	virtual sf::Vector2i steer() override;
	virtual void update() override;

};

