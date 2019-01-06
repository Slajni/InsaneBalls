#include "Game.h"
#include <algorithm>
#include <iostream>

Game::Game(sf::RenderWindow* window, std::string adress)
{
	this->gameTexture.loadFromFile(adress);
	map = new sf::Sprite(this->gameTexture);
	this->mainWindow = window;
	this->size = new sf::Vector2i(window->getSize().x, window->getSize().y);
}

Game::Game()
{
	
}


Game::~Game()
{
}

void Game::update()
{
	this->mainWindow->clear();
	this->mainWindow->draw(*this->map);
	this->updateMoves();
	for (auto i : this->objectsOnMap)
	{
		i->update();
		this->mainWindow->draw(i->gSprite());
	}
	this->mainWindow->display();
}

void Game::addMapObject(MapObject * obj)
{
	this->objectsOnMap.push_back(obj);
}

void Game::updateMoves()
{
	for (auto i : objectsOnMap)
	{
		objectsOnMap.erase(std::remove_if(objectsOnMap.begin(), objectsOnMap.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			objectsOnMap.end());
	}
	for (auto i : objectsOnMap)
	{
		std::cout << i->getPosition()->x << " " << i->getPosition()->y << std::endl;
		if (i->getPosition()->x < 0 || i->getPosition()->x > 800)
			i->negateDx();
		if (i->getPosition()->y < 0 && i->getDxes().y > 0)
			i->setDy(1.0);
	}
}
