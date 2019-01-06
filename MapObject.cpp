#include "MapObject.h"



MapObject::MapObject()
{
}

MapObject::MapObject(const sf::Texture & text, int x, int y)
{
	this->texture = text;
	this->startX = x;
	this->startY = y;
	this->id = MapObject::nextId;
	MapObject::nextId++;
	this->sprite = new sf::Sprite(this->texture);
	this->sprite->setPosition(x, y);
}


MapObject::~MapObject()
{
}

sf::Sprite MapObject::gSprite()
{
	return *this->sprite;
}

void MapObject::move(float x, float y, float dx, float dy, float multiplierX, float multiplierY)
{
	{
		sprite->move(sf::Vector2f(x * multiplierX * dx, y * multiplierY * dy));
	}
}

int MapObject::nextId = 0;