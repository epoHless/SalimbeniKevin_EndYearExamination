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

		_manager->pollEvents([this](sf::Event) { this->set_events(evt); }, evt);
		
		/*sf::Event evt{};
		while (_manager->gameWindow->pollEvent(evt))
		{

		}*/

		_manager->update(gameobjects);
		_manager->draw();

		if (_manager->isFpsLimited)
		{
			sf::sleep(sf::seconds(1.0f / _manager->maxFPS));
		}
	}
}

void GameManager::set_events(sf::Event evt)
{
	if (evt.type == sf::Event::EventType::Closed)
	{
		_manager->gameWindow->close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	}
}

void GameManager::initialize()
{	
	WTGD::Component* health = new WTGD::Component("Health");

	WTGD::GameObject* Player = new WTGD::GameObject("player");
	Player->add_component(health);

	gameobjects.push_back(Player);

	WTGD::GameObject* enemy = new WTGD::GameObject("enemy");
	gameobjects.push_back(enemy);

	_manager->createWindow(1280, 720, "Title");

	/* To be filled with
	
		add gameobjects to the game

	*/
}

