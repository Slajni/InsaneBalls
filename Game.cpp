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
	this->mainWindow->display();
}
