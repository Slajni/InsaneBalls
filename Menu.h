#pragma once
#include "SFML/Graphics.hpp"



class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Texture menuBackground;
	sf::Sprite menuSprite;
	sf::Font font;
	sf::Text menu[2];

};
