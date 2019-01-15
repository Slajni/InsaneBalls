#pragma once
#include <SFML/Graphics.hpp>
class MapObject
{
private:

	sf::RenderWindow * parentWindow; //window which holds the object
	sf::Texture texture;
	sf::Sprite * sprite;
	int id;
	static int nextId;
	sf::Vector2i * position;

public:
	MapObject();
	MapObject(const sf::Texture & text, int x, int y, sf::RenderWindow * window);
	~MapObject();

	sf::Sprite * gSprite();
	sf::RenderWindow * gParentWindow();
	void changePosition(int x, int y);
	virtual void update();
	sf::Vector2i * getPosition();
	void setPosition(int x, int y);
	int returnId();
	
};

