#include "Game.h"
#include <algorithm>
#include <iostream>

bool Game::isCollide(sf::Sprite * s1, sf::Sprite * s2)
{
	return s1->getGlobalBounds().intersects(s2->getGlobalBounds());
}

void Game::addMovable(Movable * obj)
{
	movables.push_back(obj);
}

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
	if (this->mainWindow != nullptr)
		delete this->mainWindow;
	if (this->size != nullptr)
		delete this->size;
	if (this->map != nullptr)
		delete this->map;
	if (this->paddle != nullptr)
		delete this->paddle;
}

void Game::update()
{
	this->mainWindow->clear();
	this->mainWindow->draw(*this->map);
	this->updateMoves();

	if (shrinkerClock.getElapsedTime() > sf::seconds(10) && shrinked)
	{
		extendPaddle();
		shrinked = false;
	}
	if (extenderClock.getElapsedTime() > sf::seconds(10) && extended)
	{
		shrinkPaddle();
		extended = false;
	}
	for (auto i : this->objectsOnMap)
	{
		i->update();
		this->mainWindow->draw(*i->gSprite());
	}
	this->mainWindow->display();
}

void Game::addMapObject(MapObject * obj)
{
	this->objectsOnMap.push_back(obj); 
	std::cout << this->objectsOnMap.size() << " " << obj->getPosition()->x << " " << obj->getPosition()->y << std::endl;
}

void Game::addBall(Ball * obj)
{
	this->balls.push_back(obj);
	this->addMapObject(obj);
	this->addMovable(obj);
}

void Game::addPaddle(Paddle * obj)
{
	this->paddle = obj;
	this->addMapObject(obj);
}

void Game::addModifier(Modifier * obj)
{
	this->modifiers.push_back(obj);
	this->addMapObject(obj);
	this->addMovable(obj);
}

void Game::addHollowBall(HollowBall * obj)
{
	addMapObject(obj);
	this->hollowBall = obj;
}

int Game::getLives()
{
	return lives;
}

void Game::addLive()
{
	lives++;
}

void Game::takeLifeAway()
{
	lives--;
}

void Game::updateMoves()
{
	for (auto i : balls)
	{
		if (isCollide(i->gSprite(), this->paddle->gSprite()))
			i->negateDy();
		if (isCollide(i->gSprite(), hollowBall->gSprite()))
		{
			i->negateDx();
			i->negateDy();
		}

		movables.erase(std::remove_if(movables.begin(), movables.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			movables.end());
		balls.erase(std::remove_if(balls.begin(), balls.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			balls.end());
		objectsOnMap.erase(std::remove_if(objectsOnMap.begin(), objectsOnMap.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			objectsOnMap.end());
		if (i->getPosition()->y > 800)
		{
			delete i;
			std::cout << this->objectsOnMap.size() << std::endl;
			this->lives--;
			std::cout << std::endl << "You have " << this->getLives() << " lives left\n";
		}
	}
	for (auto i : modifiers)
	{
		movables.erase(std::remove_if(movables.begin(), movables.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			movables.end());
		modifiers.erase(std::remove_if(modifiers.begin(), modifiers.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			modifiers.end());
		objectsOnMap.erase(std::remove_if(objectsOnMap.begin(), objectsOnMap.end(),
			[](const auto& i) { return i->getPosition()->y > 800; }),
			objectsOnMap.end());
		if (isCollide(i->gSprite(), paddle->gSprite()))
		{
			char efct = i->effect();
			switch (efct)
			{
			case 'h':
			{
				if (getLives() <= 10)
					addLive();
				std::cout << "You have " << getLives() << " lives left\n";
				break;
			}
			case 'd':
			{
				takeLifeAway();
				std::cout << "You have " << getLives() << " lives left\n";
				break;
			}
			case 'e':
			{
				extendPaddle();
				extenderClock.restart();
				extended = true;
			}
			case 's':
			{
				shrinkPaddle();
				shrinkerClock.restart();
				shrinked = true;
			}
			default:
				break;

			}
		}
		if (i->getPosition()->y > 800)
		{
			delete i;
			std::cout << this->objectsOnMap.size() << std::endl;
		}
	}
	for (auto i : movables)
	{
		//std::cout << i->getPosition()->x << " " << i->getPosition()->y << std::endl;
		if (i->getPosition()->x < 0 || i->getPosition()->x > 800)
			i->negateDx();
		if (i->getPosition()->y < 0 && i->getDirections().y < 0)
			i->negateDy();
		
		for(auto i: balls)
			for (auto j : balls)
			{
				if (j != i)
				{
					if (isCollide(i->gSprite(), j->gSprite()))
					{
						i->negateDx();
						i->negateDy();
					}
				}
			}
		
	}
}

void Game::shrinkPaddle()
{
	this->paddle->gSprite()->scale(0.5, 1);
	this->paddle->shrinkSize();
}

void Game::extendPaddle()
{
	this->paddle->gSprite()->scale(2, 1);
	this->paddle->extendSize();
}
