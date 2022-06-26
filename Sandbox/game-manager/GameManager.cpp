#include "GameManager.h"
#include <iostream>

void GameManager::run()
{
	initialize();

	_manager->lastTime = _manager->timeManager.GetCurrentTime();
	while (_manager->gameWindow->isOpen())
	{
		_manager->updateGameTime();
		std::cout << "FPS: " << _manager->getFPS() << std::endl;

		_manager->pollEvents();

		_manager->update(gameobjects);
		_manager->draw(gameobjects);

		if (_manager->isFpsLimited)
		{
			sf::sleep(sf::seconds(1.0f / _manager->maxFPS));
		}
	}
}

void GameManager::initialize()
{	

	WTGD::Character* player = new WTGD::Character(new WTGD::KeyboardController(), "Player");
	player->renderer->set_texture("res\\pacman.png");
	player->transform->set_scale(100, 100);
	player->transform->set_position(640, 360);
	gameobjects.push_back(player);

	WTGD::WorldObject* square = new WTGD::WorldObject("Cube", true);
	square->transform->set_scale(100, 100);
	square->transform->set_position(500, 100);

	WTGD::WorldObject* square1 = new WTGD::WorldObject("Cube", true);
	square1->transform->set_scale(100, 100);
	square1->transform->set_position(100, 100);

	gameobjects.push_back(square);
	gameobjects.push_back(square1);

	_manager->add_colliders(gameobjects);

	_manager->createWindow(1280, 720, "Title");
}

