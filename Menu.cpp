#include "Menu.h"


Menu::Menu(float width, float height)
{
	font.loadFromFile("arial.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (2 + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Blue);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (2 + 1) * 2));

	selectedItemIndex = 0;

	menuBackground.loadFromFile("images/menuBackground.png");
	menuSprite = sf::Sprite(menuBackground);
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(menuSprite);
	for (int i = 0; i < 2; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 2)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}