#include "LoopManager.h"

WTGD::LoopManager::~LoopManager()
{
	delete gameWindow;
	delete this;
}

void WTGD::LoopManager::createWindow(const float width, const float height, const char* title)
{
	set_input_func([this](sf::Event) { this->base_input_func(); }, input_event);
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

void WTGD::LoopManager::draw(std::vector<GameObject*> gameobjects)
{
	gameWindow->clear();

	/* To be filled with

		for all the entities in game
			get entity renderer
			draw the renderer
	*/

	for each (auto go in gameobjects)
	{
		const auto renders = go->get_components<Transform>();

		for each (auto rend in renders)
		{
			gameWindow->draw(*rend->get_transform());
		}
	}

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

void WTGD::LoopManager::fixed_update(std::vector<GameObject*> gameobjects)
{
	for (GameObject* go : gameobjects)
	{
		if (go->is_tick_enabled() && go->is_active) go->on_fixed_update(elapsedTime);

		Collider* collider = go->get_component<Collider>();
		if (collider)
		{
			collider->check_collision(activeColliders);
		}
	}
}

void WTGD::LoopManager::run(std::vector<GameObject*> gameobjects)
{
	lastTime = timeManager.GetCurrentTime();
	while (gameWindow->isOpen())
	{
		updateGameTime();
		printf("FPS %i\n", getFPS());

		pollEvents();

		if (fixedUpdateEnabled)
		{
			while (lag >= msForFixedUpdate)
			{
				fixed_update(gameobjects);
				lag -= msForFixedUpdate;
			}
		}

		update(gameobjects);
		draw(gameobjects);

		if (isFpsLimited)
		{
			sf::sleep(sf::seconds(1.0f / maxFPS));
		}
	}
}

void WTGD::LoopManager::pollEvents()
{
	sf::Event evt = input_event;
	while (gameWindow->pollEvent(evt))
	{		
		input_func(evt);

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
	lag += elapsedTime;
}

void WTGD::LoopManager::add_colliders(std::vector<GameObject*> gameobjects)
{
	for (GameObject* go : gameobjects)
	{
		Collider* collider = go->get_component<Collider>();
		if (collider)
		{
			if (collider->is_enabled())
			{
				activeColliders.push_back(collider);
			}
		}
	}
}
