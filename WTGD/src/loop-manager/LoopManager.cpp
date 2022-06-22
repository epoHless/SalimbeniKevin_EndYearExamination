#include "LoopManager.h"

WTGD::LoopManager::~LoopManager()
{
	delete gameWindow;
	delete this;
}

void WTGD::LoopManager::createWindow(const float width, const float height, const char* title)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void WTGD::LoopManager::setMaxFPS(unsigned newLimit)
{
	maxFPS = newLimit;
}

unsigned WTGD::LoopManager::getFPS() const
{
	return 1 / elapsedTime;
}

void WTGD::LoopManager::fpsLimitToggler()
{
	isFpsLimited = !isFpsLimited;
}

void WTGD::LoopManager::draw()
{
	gameWindow->clear();

	/* To be filled with

		for all the entities in game
			get entity renderer
			draw the renderer
	*/

	gameWindow->display();
}

void WTGD::LoopManager::update(std::vector<GameObject*> gameobjects)
{
	/* To be filled with

		for all the gameobjects in the game
			if is active and enabled
				update it

	*/

	for (GameObject* go : gameobjects)
	{
		if (go->is_tick_enabled() && go->is_active) go->on_update(elapsedTime);
	}
}

void WTGD::LoopManager::pollEvents(std::function<void(sf::Event)> func, sf::Event eventt)
{
	sf::Event evt = eventt;
	while (gameWindow->pollEvent(evt))
	{		
		func(evt);

		if (evt.type == sf::Event::EventType::Closed)
		{
			gameWindow->close();
		}
	}
}

void WTGD::LoopManager::updateGameTime()
{
	currentTime = timeManager.GetCurrentTime();
	elapsedTime = TimeManager::GetElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
	lastTime = currentTime;
}