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
	int startX, startY;

public:
	MapObject();
	MapObject(const sf::Texture & text, int x, int y, sf::RenderWindow * window);
	~MapObject();

	sf::Sprite gSprite();
	sf::RenderWindow * gParentWindow();
	void changePosition(int x, int y);
	void move(float x, float y, float dx = 1.0, float dy = 1.0, float multiplierX = 1.0, float multiplierY = 1.0);
	virtual void update();

};

