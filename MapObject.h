#pragma once
#include <SFML/Graphics.hpp>
class MapObject
{
private:

	sf::Texture texture;
	sf::Sprite * sprite;
	int id;
	static int nextId;
	int startX, startY;

public:
	MapObject();
	MapObject(const sf::Texture & text, int x, int y);
	~MapObject();

	sf::Sprite gSprite();
};

