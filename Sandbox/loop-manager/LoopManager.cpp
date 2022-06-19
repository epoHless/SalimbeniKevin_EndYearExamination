#include "LoopManager.h"
#include <iostream>


LoopManager::~LoopManager()
{
	delete gameWindow;
}

void LoopManager::createWindow(const float width, const float height, const char* title)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void LoopManager::setMaxFPS(unsigned newLimit)
{
	maxFPS = newLimit;
}

unsigned LoopManager::getFPS() const
{
	return 1 / elapsedTime;
}

void LoopManager::fpsLimitToggler()
{
	isFpsLimited = !isFpsLimited;
}

void LoopManager::run()
{
	lastTime = timeManager.GetCurrentTime();
	while (gameWindow->isOpen())
	{
		updateGameTime();
		std::cout << "FPS: " << getFPS() << std::endl;
		pollEvents();
		update();
		draw();

		if (isFpsLimited)
		{
			sf::sleep(sf::seconds(1.0f / maxFPS));
		}
	}
}

void LoopManager::initialize()
{
	/* To be filled with
	
		add gameobjects to the game

	*/
}

void LoopManager::draw()
{
	gameWindow->clear();

	/* To be filled with
	
		for all the entities in game
			get entity renderer
			draw the renderer	
	*/

	gameWindow->display();
}

void LoopManager::update()
{
	/* To be filled with

		for all the gameobjects in the game
			if is active and enabled
				update it

	*/
}

void LoopManager::pollEvents()
{
	sf::Event events{};
	while (gameWindow->pollEvent(events))
	{
		if (events.type == sf::Event::EventType::Closed)
		{
			gameWindow->close();
		}
	}
}

void LoopManager::updateGameTime()
{
	currentTime = timeManager.GetCurrentTime();
	elapsedTime = TimeManager::GetElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
	lag += elapsedTime;
	lastTime = currentTime;
}
