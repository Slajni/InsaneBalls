#include "MapObject.h"



MapObject::MapObject()
{
	delete this->position;
	delete this->sprite;
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
}

sf::Sprite MapObject::gSprite()
{
	return *sprite;
}

sf::RenderWindow * MapObject::gParentWindow()
{
	return this->parentWindow;
}

void MapObject::changePosition(int x, int y)
{
	this->sprite->setPosition(x, y);
}

void MapObject::move(float x, float y, float dx, float dy, float multiplierX, float multiplierY)
{
		this->sprite->move(sf::Vector2f(x * multiplierX * dx, y * multiplierY * dy));
}

void MapObject::update()
{
}

void MapObject::negateDx()
{
	this->defaultdx *= (-1);
}

void MapObject::negateDy()
{
	this->defaultdy *= (-1);
}

void MapObject::setDy(float x)
{
	this->defaultdy = x;
}

sf::Vector2f MapObject::getDxes()
{
	return sf::Vector2f(this->defaultdx,this->defaultdy);
}

sf::Vector2i * MapObject::getPosition()
{
	return this->position;
}

int MapObject::nextId = 0;