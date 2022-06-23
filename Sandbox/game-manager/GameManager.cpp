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

void GameManager::set_events()
{

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		_manager->set_input_func([this](sf::Event) { this->set_events_b(); }, this->evt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		printf("AAAAAAAAAAAAAAAAAAAAA\n");
	}*/
}

void GameManager::set_events_b()
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	//{
	//	_manager->set_input_func([this](sf::Event) { this->set_events(); }, this->evt);
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//{
	//	printf("BBBBBBBBBBBBBBBBBBBBB\n");
	//}
}

void GameManager::initialize()
{	
	_manager->set_input_func([this](sf::Event) { this->set_events(); }, evt);

	player = new WTGD::Character(new WTGD::KeyboardController(), "Player");
	player->renderer->set_texture("res\\pacman.png");
	player->transform->set_scale(100, 100);
	player->transform->set_position(640, 360);
	gameobjects.push_back(player);

	_manager->createWindow(1280, 720, "Title");

	/* To be filled with
	
		add gameobjects to the game

	*/
}

