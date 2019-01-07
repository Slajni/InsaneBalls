#include "MapObject.h"



MapObject::MapObject()
{
}

MapObject::MapObject(const sf::Texture & text, int x, int y, sf::RenderWindow * window)
{
	this->parentWindow = window;
	this->texture = text;
	this->position = new sf::Vector2i(x, y);
	this->id = MapObject::nextId;
	MapObject::nextId++;
	this->sprite = new sf::Sprite(this->texture);
	this->sprite->setPosition(x, y);
}


MapObject::~MapObject()
{
	if(this->position!=nullptr)
		delete this->position;
	if(this->sprite!=nullptr)
		delete this->sprite;
	if(this->parentWindow!=nullptr)
		delete this->parentWindow;
}

sf::Sprite * MapObject::gSprite()
{
	return sprite;
}

sf::RenderWindow * MapObject::gParentWindow()
{
	return this->parentWindow;
}

void MapObject::changePosition(int x, int y)
{
	this->sprite->setPosition(x, y);
}

void MapObject::update()
{
}

sf::Vector2i * MapObject::getPosition()
{
	return this->position;
}

void MapObject::setPosition(int x, int y)
{
	this->position->x = x;
	this->position->y = y;
}

int MapObject::nextId = 0;