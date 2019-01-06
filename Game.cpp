#include "Game.h"


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
	for (auto i : this->objectsOnMap)
		this->mainWindow->draw(i.gSprite());
	this->mainWindow->display();
}

void Game::addMapObject(MapObject & obj)
{
	this->objectsOnMap.push_back(obj);
}
