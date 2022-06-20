#include "GameManager.h"
#include <iostream>

void GameManager::run(WTGD::LoopManager* manager)
{
	initialize(manager);

	manager->lastTime = manager->timeManager.GetCurrentTime();
	while (manager->gameWindow->isOpen())
	{
		manager->updateGameTime();
		std::cout << "FPS: " << manager->getFPS() << std::endl;
		manager->pollEvents();
		manager->update(gameobjects);
		manager->draw();

		if (manager->isFpsLimited)
		{
			sf::sleep(sf::seconds(1.0f / manager->maxFPS));
		}
	}
}

void GameManager::initialize(WTGD::LoopManager* manager)
{
	manager->createWindow(1280, 720, "Title");

	/* To be filled with
	
		add gameobjects to the game

	*/
}

